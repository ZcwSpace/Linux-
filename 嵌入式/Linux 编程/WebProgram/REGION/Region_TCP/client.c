#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <sys/un.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>

void print_err(char *str,int line,int err_no);
void *pth_fun(void *pth_arg);
void signal_fun(int signo);

int sockfd = -1;
int ret = 0;

int main()
{
    //注册一个信号处理函数，用来删除掉bind函数绑定的用于通信的文件
    signal(SIGINT,signal_fun);

    //设置套接字文件
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if(-1 == sockfd)
    {
        print_err("socket failed", __LINE__ - 3, errno);
    }

    //调用connect与服务器建立连接
    struct sockaddr_un addr = {0};
    
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path,"./SOCK");
    ret = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if(-1 == ret)
    {
        print_err("connect failed", __LINE__ - 3, errno);
    }

    //接收数据
    pthread_t tid;

    ret = pthread_create(&tid, NULL, pth_fun, NULL);
    if(0 != ret)
    {
        print_err("pthread_create failed", __LINE__ - 3, ret);
    }

    //发送数据
    char buf[100] = {0};
    while(1)
    {
        bzero(buf,sizeof(buf));
        scanf("%s", buf);
        ret = write(sockfd, buf, sizeof(buf));
        if(-1 == ret)
        {
            print_err("write failed", __LINE__ - 3, errno);
        }
    }

    return 0;
}


//打印错误信息
void print_err(char *str,int line,int err_no)
{
    printf("%d, %s:%s\n",line,str,strerror(err_no));  

    exit(-1);
}

//接收数据
void *pth_fun(void *pth_arg)
{
    char buf[100] = {0};
    while(1)
    {
        bzero(buf, sizeof(buf));
        ret = read(sockfd, buf,sizeof(buf));
        if(-1 == ret)
        {
            print_err("read failed", __LINE__ - 3, errno);
        }
        else if(0 < ret)
        {
            printf("收到的服务器发过来的数据为：%s\n", buf);
        }
    }
}

void signal_fun(int signo)
{
    if(SIGINT == signo)
    {
        //remove("./SOCK");
        exit(0);
    }
}
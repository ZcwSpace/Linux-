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

//通信文件描述符
int cfd;
int ret = 0;

int main()
{
    //注册一个信号处理函数，用来删除掉bind函数绑定的用于通信的文件
    signal(SIGINT,signal_fun);

    //设置套接字文件
    int sockfd = -1;
    
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if(-1 == sockfd)
    {
        print_err("socket failed", __LINE__ - 3, errno);
    }

    //绑定套接字文件
    struct sockaddr_un addr = {0};
    
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path,"./SOCK");
    ret = bind(sockfd, (struct sockaddr *)&addr,sizeof(addr));
    if(-1 == ret)
    {
        print_err("bind failed", __LINE__ - 3, errno);
    }

    //将套接字文件描述符变为被动文件描述符，用于监听
    ret = listen(sockfd, 3);
    if(-1 == ret)
    {
        print_err("listen failed", __LINE__ - 3, errno);
    }

    //调用accept函数监听客户的连接
    cfd = accept(sockfd, NULL, 0);
    if(-1 == cfd)
    {
        print_err("accept failed", __LINE__ - 3, errno);
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
        ret = write(cfd, buf, sizeof(buf));
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
        ret = read(cfd, buf,sizeof(buf));
        if(-1 == ret)
        {
            print_err("read failed", __LINE__ - 3, errno);
        }
        else if(0 < ret)
        {
            printf("收到的客户发过来的数据为：%s\n", buf);
        }
    }
}

void signal_fun(int signo)
{
    if(SIGINT == signo)
    {
        remove("./SOCK");
        exit(0);
    }
}

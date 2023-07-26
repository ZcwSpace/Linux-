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
struct sockaddr_un peer_addr = {0};

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("格式应为：./* peer_region_file\n");
    }

    //注册一个信号处理函数，用来删除掉bind函数绑定的用于通信的文件
    signal(SIGINT,signal_fun);

    //创建套接字文件，直接使用返回的套接字文件描述符用于通信
    sockfd = socket(AF_UNIX, SOCK_DGRAM, 0);
    if(-1 == sockfd)
    {
        print_err("socket failed", __LINE__ - 3, errno);
    }

    //绑定固定的位置
    struct sockaddr_un addr = {0};
    
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, "./SOCK_a");
    ret = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if(-1 == ret)
    {
        print_err("bind failed", __LINE__ - 3, errno);
    }

    //次线程接收数据
    pthread_t tid;

    ret = pthread_create(&tid, NULL, pth_fun, NULL);
    if(0 != ret)
    {
        print_err("pthread_create failed", __LINE__ - 3, ret);
    }

    //主线程发送数据
    char buf[100] = {0};
    peer_addr.sun_family = AF_UNIX;
    strcpy(peer_addr.sun_path, argv[1]);

    while(1)
    {
        bzero(buf, sizeof(buf));
        scanf("%s", buf);
        ret = sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&peer_addr, sizeof(peer_addr));
        if(-1 == ret)
        {
            print_err("sendto failed", __LINE__ - 3, errno);
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
    int length = sizeof(peer_addr);

    while(1)
    {
        bzero(buf, sizeof(buf));
        ret = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&peer_addr, &length);
        if(-1 == ret)
        {
            print_err("recvfrom failed", __LINE__ - 3, errno);
        }
        else if(0 < ret)
        {
            printf("收到的b发过来的数据为：%s\n", buf);
        }
    }
}

void signal_fun(int signo)
{
    if(SIGINT == signo)
    {
        remove("./SOCK_a");
        exit(0);
    }
}
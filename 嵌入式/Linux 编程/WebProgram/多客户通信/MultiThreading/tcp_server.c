#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

void print_err(char *str,int line,int err_no);
void *pth_fun();
void signal_fun(int signo);

int main()
{
    int sockfd;
    int ret = -1;

    signal(SIGINT, signal_fun);
    
    //创建用于监听客户连接的套接字文件
    sockfd = socket(PF_INET, SOCK_STREAM, 0);
    if(-1 == sockfd)
    {
        print_err("socket failed", __LINE__ - 3, errno);
        exit(-1);
    }

    //绑定套接字文件监听的地址
    struct sockaddr_in addr = {0};

    addr.sin_family = PF_INET;
    addr.sin_port = htons(5006);
    addr.sin_addr.s_addr = inet_addr("192.168.1.39"); 
    ret = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if(-1 == ret)
    {
        print_err("bind failed", __LINE__ - 3, errno);
        exit(-1);
    }

    //设置套接字文件的监听状态为被动
    ret = listen(sockfd, 3);
    if(-1 == ret)
    {
        print_err("listen failed", __LINE__ - 3, errno);
        exit(-1);
    }

    //循环监听用户的连接请求，如果有，则创建次线程与之通信
    long cfd;
    pthread_t tid;

    while(1)
    {
        cfd = accept(sockfd, NULL, NULL);
        if(-1 == cfd)
        {
            print_err("accept failed", __LINE__ - 3, errno);
            exit(-1);
        }
        ret = pthread_create(&tid, NULL, pth_fun, (void *)cfd);
        if(ret != 0)
        {
            print_err("pthread_create failed", __LINE__ - 3, errno);
            exit(-1);
        }
    }
    
    return 0;
}

void print_err(char *str,int line,int err_no)
{
    printf("%d, %s:%s\n",line,str,strerror(err_no));  

    exit(-1);
}

void *pth_fun(void *pth_arg)
{
    long cfd = (long)pth_arg;
    int ret = -1;
    char buf[100];

    while(1)
    {
        bzero(buf,sizeof(buf));
        ret = recv(cfd, &buf, sizeof(buf), 0);
        if(-1 == ret)
        {
            print_err("recv failed", __LINE__ - 3, errno);
            exit(-1);
        }
        else if(0 < ret)
        {
            printf("client say: %s\n", buf);
            ret = send(cfd, "server already sent\n", sizeof("server already sent\n"), 0);
            if(-1 == ret)
            {
                print_err("send failed", __LINE__ - 3, errno);
                exit(-1);
            }
        }
    }
}

void signal_fun(int signo)
{
    if(signo == SIGINT)
    {
    }
}
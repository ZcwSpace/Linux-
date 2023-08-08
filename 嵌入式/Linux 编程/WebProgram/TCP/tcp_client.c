#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

#define SPORT 5006
#define SIP "127.0.0.1" 

typedef struct data
{
    int id;
    char name[30];
}Data;

int sockfd;
int ret;

void print_err(char *str,int line,int err_no);
void *pth_fun(void *pth_org);
void signal_fun(int signo);

int main()
{
    signal(SIGINT, signal_fun);

    //创建套接字文件，并指定使用TCP协议
    sockfd = socket(PF_INET, SOCK_STREAM, 0);
    if(sockfd == -1)
    {
        print_err("create socket file failed",__LINE__ - 3, errno);
    }

    //向服务器发起三次握手，三次握手由TCP自动完成
    struct sockaddr_in seraddr = {0};

    seraddr.sin_family = AF_INET;
    seraddr.sin_addr.s_addr = inet_addr(SIP);
    seraddr.sin_port = htons(SPORT);

    ret = connect(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));
    if(ret == -1)
    {
        print_err("connect failed",__LINE__ - 3, errno);
    }

    //收发数据
    pthread_t tid;
    ret = pthread_create(&tid, NULL, pth_fun,  NULL);
    if(ret != 0)
    {
        print_err("pthread_create failed",__LINE__ - 3, errno);
    }

    Data stu;
    int tem_num;
    while(1)
    {
        bzero(&stu,sizeof(stu));
        printf("请输入学生学号：\n");
        scanf("%d",&tem_num);
        stu.id = htonl(tem_num);
        printf("请输入学生姓名：\n");
        scanf("%s",stu.name);
        ret = send(sockfd, (void *)&stu, sizeof(stu), 0);

        if(ret == -1)
        {
            print_err("send failed",__LINE__ - 3, errno);
        }
    }
    


    return 0;
}

//报错
void print_err(char *str,int line,int err_no)
{
    printf("%d, %s:%s\n",line,str,strerror(err_no));  

    exit(-1);
}

//
void *pth_fun(void *pth_org)
{
    Data stu;

    while(1)
    {
        bzero(&stu,sizeof(stu));
        ret = recv(sockfd, (void *)&stu, sizeof(stu), 0);
        if(ret == -1)
        {
            print_err("recv failed",__LINE__ - 3, errno);
        }
        else if(ret >0)
        {
            printf("sid = %d, sname = %s\n", ntohl(stu.id), stu.name);
        }

    }
}

void signal_fun(int signo)
{
    if(signo == SIGINT)
    {
        //close(cfd);
        shutdown(sockfd, SHUT_RDWR);
        exit(0);
    }
}
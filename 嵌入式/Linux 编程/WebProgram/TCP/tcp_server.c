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

#define SPORT 5006
#define SIP "127.0.0.1" 
int cfd = -1;//套接字文件描述符

typedef struct data
{
    int id;
    char name[30];
}Data;

//封装应用层的数据
//学生信息

void print_err(char *str,int line,int err_no);
void *pth_recv();
void signal_fun(int signo);

int main()
{
    int sockfd;

    signal(SIGINT, signal_fun);
    
    //指定所要使用的协议的套接字文件
    sockfd=socket(PF_INET,SOCK_STREAM,0);
    if(sockfd==-1)
    {
        print_err("socket fail",__LINE__-3,errno);
        
        exit(-1);
    }

    //绑定套接字文件、IP地址和端口。
    int bind_ret;
    struct sockaddr_in addr;

    addr.sin_family=AF_INET;//指定IP地址格式
    addr.sin_port=htons(SPORT);// 设置端口号
    addr.sin_addr.s_addr=inet_addr(SIP);//跨网通信时，IP地址要指定为公网IP；
    bind_ret=bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
    if(bind_ret==-1)
    {
        print_err("bind fail",__LINE__-3,errno);

        exit(-1);
    }
    
    //listen：将套接字文件描述符从主动文件描述符变为被动文件描述符，然后用于监听客户的连接。
    int listen_ret;
    
    listen_ret=listen(sockfd,3);
    if(listen_ret==-1)
    {
        print_err("listen fail",__LINE__-3,errno);

        exit(-1);
    }

    //调用accept函数，被动监听客户的连接
    struct sockaddr_in clnaddr = {0};//用于记录发起连接请求的那个客户的IP地址和端口号
    int clnaddr_size = sizeof(clnaddr);//用于记录clnaddr的大小
    
    cfd = accept(sockfd, (struct sockaddr *)&clnaddr, &clnaddr_size);
    if(cfd == -1)
    {
        print_err("accept fail",__LINE__-3,errno);
    }
    
    //获得用户的ip地址和端口号
    /*
    int CIP = 0;
    int CPORT = 0;

    CIP = inet_ntoa(clnaddr.sin_addr);
    CPORT= ntohs(clnaddr.sin_port);
    */
    printf("客户的IP地址 = %s, 端口号 = %d\n", inet_ntoa(clnaddr.sin_addr), ntohs(clnaddr.sin_port));

    //接收数据
    pthread_t tid;

    pthread_create(&tid, NULL,pth_recv,NULL);
    //发送数据
    int data_length = 0;
    int temp_id;
    Data stu = {0};

    while(1)
    {
        printf("input id：\n");
        scanf("%d",&temp_id);
        stu.id=htonl(temp_id);
        printf("input name：\n");
        //char不需要进行端序的转换
        scanf("%s",stu.name);
        data_length = send(cfd,(void *)&stu,sizeof(stu),0);
        if(data_length == -1)
        {
            print_err("send fail",__LINE__-3,errno);
        }
    }
    
    return 0;
}

void print_err(char *str,int line,int err_no)
{
    printf("%d, %s:%s\n",line,str,strerror(err_no));  

    exit(-1);
}

void *pth_recv(void *pth_arg)
{
    int ret = 0;
    Data data;

    while(1)
    {
        bzero(&data, sizeof(data));
        ret = recv(cfd, (void *)&data, sizeof(data), 0);
        if(ret == -1)
        {
            print_err("recv fail",__LINE__-3,errno);
        }
        else if(ret >0)
        {
            printf("id = %d, name = %s\n",ntohl(data.id),data.name);
        }
    }
}

void signal_fun(int signo)
{
    if(signo == SIGINT)
    {
        //close(cfd);
        shutdown(cfd, SHUT_RDWR);
        exit(0);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <string.h>
#include <errno.h>

#define SPORT 5006
#define SIP "192.168.1.1" 

struct in_addr
{
    unsigned int s_addr;
};

struct sockaddr_in
 {    
    short            sin_family;       // 设置地址族AF_***
    unsigned short   sin_port;    // 设置端口号
    struct in_addr   sin_addr;     // 设置IP地址
    unsigned char __pad[sizeof(struct sockaddr)-sizeof(short int)-sizeof(unsigned short int)-sizeof(struct in_addr)];
};

void print_err(char *str,int line,int err_no);

int main()
{
    int sockfd;
    
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

        exir(-1);
    }
    
    return 0;
}

void print_err(char *str,int line,int err_no)
{
    printf("%d, %s:%s\n",line,str,strerror(err_no));  

    exit(-1);
}
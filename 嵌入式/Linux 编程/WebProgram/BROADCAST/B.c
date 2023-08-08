#include <sys/types.h>          
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int sockfd;
int ret;
struct sockaddr_in dest_addr;

void print_err(char *str, int line, int err_no);
void *pth_recv(void *pth_arg);

int main(int argc, char * argv)
{
    if(argc != 3)
    {
        printf("你输入的格式应为：可执行文件 目标ip 目标端口\n");
        exit(0);
    }
    //调用socket创建套接字文件得到文件描述符
    sockfd = socket(PF_INET, SOCK_DGRAM, 0);
    if(sockfd == -1)
    {
        print_err("socket fail", __LINE__ - 3, errno);
    }

    int on=1;
    setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR | SO_BROADCAST,&on,sizeof(on));

    //调用bind绑定固定的ip和端口
    struct sockaddr_in addr; 

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(5009);
    ret = bind(sockfd, (struct sockaddr *)&addr,sizeof(addr));
    if(ret == -1)
    {
        print_err("bind fail", __LINE__ - 3, errno);
    }

    //发送数据
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    dest_addr.sin_port = htons(5006); 

    //接收数据
    pthread_t tid;

    pthread_create(&tid, NULL,pth_recv,NULL);

    char buf[30];
    while(1)
    {
        bzero(buf,sizeof(buf));
        scanf("%s", buf);
        ret = sendto(sockfd, (void *)&buf, sizeof(buf), 0,(struct sockaddr *)&dest_addr, sizeof(dest_addr));
        if(ret == -1)
        {
            print_err("sendto fail", __LINE__ - 3, errno);
        }
    }

    return 0;
}

void print_err(char *str,int line,int err_no)
{
    printf("%d, %s:%s\n",line,str,strerror(err_no));  

    exit(-1);
}

//接收数据
void *pth_recv(void *pth_arg)
{
    char buf[30];
    int length;
    int ret_recv;

    while(1)
    {
        bzero(&buf, sizeof(buf));
        length = sizeof(dest_addr);
        ret_recv = recvfrom(sockfd, (void *)&buf, sizeof(buf), 0,(struct sockaddr *)&dest_addr, &length);
        if(ret_recv == -1)
        {
            print_err("recvfrom fail",__LINE__-3,errno);
        }
        else if(ret_recv > 0)
        {
            printf("B收到来自%s：%d数据为：%s\n", inet_ntoa(dest_addr.sin_addr),dest_addr.sin_port,buf);
        }
    }
}
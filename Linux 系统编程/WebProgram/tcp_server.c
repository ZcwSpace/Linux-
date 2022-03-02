#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <string.h>
#include <errno.h>

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


    return 0;
}

void print_err(char *str,int line,int err_no)
{
    printf("%d, %s:%s\n",line,str,strerror(err_no));  

    exit(-1);
}
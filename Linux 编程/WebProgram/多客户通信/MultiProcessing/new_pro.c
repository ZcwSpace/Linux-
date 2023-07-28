#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>

void print_err(char *str,int line,int err_no);

int main(int argc, char **argv)
{
    long cfd = atoi(argv[1]);
    int ret = -1;
    char buf[100];

    printf("cfd:%d\n");
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

    return 0;
}

void print_err(char *str,int line,int err_no)
{
    printf("%d, %s:%s\n",line,str,strerror(err_no));  

    exit(-1);
}
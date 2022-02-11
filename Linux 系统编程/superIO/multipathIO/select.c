#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

void print_err(char *str,int line,int err_no);

int main(void)
{
    int mousefd;

    mousefd=open("/dev/input/mouse3",O_RDONLY);
    if(mousefd==1)
    {
        print_err("open mouse fial",__LINE__-3,errno);
    }


    int ret=0;
    fd_set readfds;
    char buf[100]={0};
    int mouse_date;
    struct timeval timeout;

    while(1)
    {
        label:
            FD_ZERO(&readfds);//先将集合全部清空
            FD_SET(0,&readfds);//将fd放到集合中
            FD_SET(mousefd,&readfds);
            //设置超时时间
            timeout.tv_sec=3;
            timeout.tv_usec=0;
            ret=select(mousefd+1,&readfds,NULL,NULL,&timeout);
        if(ret==-1&&errno==EINTR)
        {
            goto label;
        }
        else if(ret<=-1)
        {
            print_err("select errno",__LINE__-7,errno);
        }
        else if(ret>0)
        {
            if(FD_ISSET(0,&readfds))
            {
                bzero(&buf,100);
                ret=read(0,buf,sizeof(buf));
                if(ret>0)
                {
                    printf("%s\n",buf);
                }
            }
            if(FD_ISSET(mousefd,&readfds))
            {
                ret=read(mousefd,&mouse_date,sizeof(mouse_date));
                if(ret>0)
                {
                    printf("%d\n",mouse_date);
                }
            }
        }
        else if(ret==0)
        {
            printf("slelct timeout!\n");
        }
    }

    return 0;
}

void print_err(char *str,int line,int err_no)
{
    printf("%d, %s:%s\n",line,str,strerror(err_no));  

    exit(-1);
}
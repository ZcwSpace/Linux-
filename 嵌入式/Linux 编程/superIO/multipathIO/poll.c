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
#include <poll.h>

void print_err(char *str,int line,int err_no);

int main(void)
{
    int mousefd,poll_ret,read_ret;
    struct pollfd fds[2];
    char key_buf[100]={0};
    long mouse_buf;

    mousefd=open("/dev/input/mouse3",O_RDONLY);
    if(mousefd==1)
    {
        print_err("open mouse fial",__LINE__-3,errno);
    }
    //设置数组
    fds[0].fd=0;
    fds[0].events=POLLIN;
    fds[1].fd=mousefd;
    fds[1].events=POLLIN;
    while(1)
    {
        label:
            poll_ret=poll(fds,2,3000);
        if(poll_ret>0)
        {
            if(fds[0].events==fds[0].revents)
            {
                bzero(key_buf,sizeof(key_buf));
                read_ret=read(0,key_buf,sizeof(key_buf));
                if(read_ret>0)
                {
                    printf("%s\n",key_buf);
                }
            }
            if(fds[1].events==fds[1].revents)
            {
                read(mousefd,&mouse_buf,sizeof(mouse_buf));
                printf("%d\n",mouse_buf);
            }

        }
        else if(poll_ret==0)
        {
            printf("timeout!\n");
        }
        else if(poll_ret==-1&&errno==EINTR)
        {
            goto label;
        }
        else
        {
            printf("poll fail",35,errno);
        }
    }

    return 0;
}

void print_err(char *str,int line,int err_no)
{
    printf("%d, %s:%s\n",line,str,strerror(err_no));  

    exit(-1);
}
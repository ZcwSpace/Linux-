#include<stdio.h>
#include<stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include<errno.h>
#include<sys/types.h>

void rm(char *str);

int main(int argc, char** argv)
{
    if(argc!=2)
    {
        printf("输入错误！");
        exit(0);
    }
    rm(argv[1]);
    printf("clean success！\n");

    return 0;
}
void rm(char *str)
{
    struct stat sta;
    char fileType,buf[100]={0};
    int ret;

    printf("str=%s\n",str);
    ret=lstat(str,&sta);
    if(ret==-1)
    {
        perror("lsata fail");
        exit(-1);
    }
    if( S_ISDIR(sta.st_mode)) 
    {
        ret=rmdir(str);
        if(ret==-1)
        {
            DIR *dirp=NULL;
            struct dirent *direntp=NULL;
            dirp=opendir(str);
            if(NULL==dirp)
            {
                perror("opendir fail");
                exit(-1);
            }
            while(1)
            {
                direntp=readdir(dirp);
                if(direntp==NULL &&errno!=0)
                {
                    perror("readdir fail");
                    exit(-1);
                }
                if(direntp==NULL &&errno==0)
                {
                    break;
                }
                ret=chdir(str);
                if(ret==-1)
                {
                    perror("chdir error");
                    exit(-1);
                }
                if(direntp->d_name!=".."&&direntp->d_name!=".")
                {
                    rm(direntp->d_name);
                }
            }
            ret=rmdir(str);
            if(ret==-1)
            {
                perror("rmdir fail");
                exit(-1);
            }
        }
    }
    else
    {
        ret=unlink(str);
        if(ret==-1)
        {
            perror("unlink fail");
            exit(-1);
        }
    }
}
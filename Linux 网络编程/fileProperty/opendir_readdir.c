#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include<errno.h>

int main(int argc,char** argv)
{
    DIR *dirp=NULL;
    struct dirent *direntp=NULL;

    dirp=opendir(argv[1]);
    if(NULL==dirp)
    {
        perror("opendir fail");
        exit(-1);
    }
    /*
    struct dirent {
               ino_t          d_ino;       /* Inode number 
               off_t          d_off;       /* 地址偏移
               unsigned short d_reclen;    /* Length of this record 
               unsigned char  d_type;      /* Type of file; not supported
                                              by all filesystem types 
               char           d_name[256]; /* 文件名
                
           };
    */
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
        printf("fname=%s ",direntp->d_name);
    }
    return 0;
}
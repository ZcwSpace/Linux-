#ifndef H_FILE_LOCK_H
#define H_FILE_LOCK_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

//定义fcntl函数经常用到的常量
#define N_B_W(fd,whence,start,len)\/*NO BLOCK WRITE*/
    set_filelock(fd,F_SETLK,F_WRLCK,whence,start,len);
#define N_B_R(fd,whence,start,len)\/*NO BLOCK READ*/
    set_filelock(fd,F_SETLK,F_RDLCK,whence,start,len);
#define B_W(fd,whence,start,len)\/*BLOCK WRITE*/
    set_filelock(fd,F_SETLKW,F_WRLCK,whence,start,len);
#define B_R(fd,whence,start,len)\/*BLOCK READ*/
    set_filelock(fd,F_SETLKW,F_RDLCK,whence,start,len);
#define UN_LOCK(fd,whence,start,len)\
    set_filelock(fd,F_SETLK,F_UNLCK,whence,start,len);

//定义函数用以实现文件锁
static void set_filelock(int fd,int cmd,short type,short whence,off_t start,off_t len)
{
    int ret=0;
    struct flock f_lock;

    //初始化结构体成员
    f_lock.l_type=type;
    f_lock.l_whence=whence;
    f_lock.l_start=start;
    f_lock.l_len=len;

    ret=fcntl(fd,cmd,&f_lock);
    if(ret==-1)
    {
        perror("fcntl fail\n");

        exit(-1);
    }
} 

#endif

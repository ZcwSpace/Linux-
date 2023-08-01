#include <stdio.h>
#include <stdlib.h>
#include "recode_lock.h"

int main(void)
{	
    int ret = 0, fd = -1;
        
    fd = open("./file", O_CREAT|O_RDWR|O_APPEND|O_TRUNC, 0777);
    if(fd < 0)
    {	
        perror("open is fail");
        exit(-1);
    }	
    
    while(1)
    {
        //加阻塞读锁，也就是加锁失败，程序会休眠在这里，就像scanf没有数据，也会休眠一样
        read_lockw(fd, SEEK_SET, 0, 0); 
        //#define read_lockw(fd, l_whence, l_start, l_len) \
    lock_set(fd, F_SETLKW, F_RDLCK, SEEK_SET, 0, 0)
        
        write(fd, "hello ", 6);
        write(fd, "world\n", 6);
        
        unlock(fd, SEEK_SET, 0, 0); //解锁
    }	
}		
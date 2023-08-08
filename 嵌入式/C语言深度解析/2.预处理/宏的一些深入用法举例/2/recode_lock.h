#ifndef ___RECODE_LOCK__
#define ___RECODE_LOCK__

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


/* 加非阻塞读锁 */
#define read_lock(fd, l_whence, l_start, l_len) \
    lock_set(fd, F_SETLK, F_RDLCK, l_whence, l_start, l_len)//带参宏

/* 加阻塞读锁 */
#define read_lockw(fd, l_whence, l_start, l_len) \
    lock_set(fd, F_SETLKW, F_RDLCK, l_whence, l_start, l_len)

/* 加非阻塞写锁 */
#define write_lock(fd, l_whence, l_start, l_len) \
    lock_set(fd, F_SETLK, F_WRLCK, l_whence, l_start, l_len)

/* 加阻塞写锁 */
#define write_lockw(fd, l_whence, l_start, l_len) \
    lock_set(fd, F_SETLKW, F_WRLCK, l_whence, l_start, l_len)

/* 解锁 */
#define unlock(fd, l_whence, l_start, l_len) \
    lock_set(fd, F_SETLK, F_UNLCK, l_whence, l_start, l_len)

    
/* 操作锁的函数 */
static int lock_set(int fd, int l_ifwset, short l_type, short l_whence, \
    off_t l_start, off_t l_len)
{
    int ret = -1;
    struct flock f_lock;
    
    f_lock.l_type = l_type;
    f_lock.l_whence = l_whence;
    f_lock.l_start = l_start;
    f_lock.l_len = l_len;
    
    ret = fcntl(fd, l_ifwset, &f_lock);//加锁解锁
    
    return(ret);
}

#endif
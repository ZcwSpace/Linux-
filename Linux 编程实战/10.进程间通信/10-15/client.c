#include<sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include<stdlib.h>
#include<stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds buf;    /* Buffer for IPC_STAT, IPC_SET */
 };

void print_err(char *string);

int main(void)
{
    __key_t key;
    int semid;
    struct sembuf sbuf={0,-1,SEM_UNDO};
    struct sembuf sbuf1={0,1,SEM_UNDO};
    union semun semopts;

    key=ftok(".",'s');
    if(key==-1)
    {
        print_err("ftok fail");
    } 

    semid=semget(key,1,IPC_CREAT|0664);//key 信号量个数  
    if(semid==-1)
    {
        print_err("semget fail");
    }

    int ctl_ret;

    semopts.val=1;
    ctl_ret=semctl(semid,0,SETVAL,1);
    //信号量集合标识符 集合当中某个信号量的编号 设置初始值 初始值
    if(ctl_ret==-1)
    {
    
        print_err("semctl fail");
    }
    
    int op_ret,fd;

    fd==open("./file.txt",O_RDWR|O_CREAT|O_TRUNC,0664);
    while(1)
    {
        op_ret=semop(semid,&sbuf,1);
        //信号量集合标识符 pv 数组元素的个数
        if(op_ret==-1)
        {
            print_err("semop fail");
        }
        write(fd,"hello\n",6);
        op_ret=semop(semid,&sbuf1,1);
    }
    

    return 0;
}
void print_err(char *string)
{
    perror(string);

    exit(1);
}
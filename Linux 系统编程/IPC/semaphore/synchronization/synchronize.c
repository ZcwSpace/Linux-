#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <fcntl.h>
//#include "semaphore.h"
#include <unistd.h>
#include<signal.h>


#define NSEMS 3 

void get_sem(int sem_num);
void print_error(char *str);
void init_sem(int sem_num,int val);
void delete_sem();
void signal_catch(int signal_index);
void p_sem(int sem_num);
void v_sem(int sem_num);

union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  array;  /* Array for GETALL, SETALL */
 };

int semid;

int main(void)
{
    int fork_ret;
    int vales[3]={1,0,0};

    get_sem(NSEMS);

    for(int i=0;i<NSEMS;i++)
    {
        init_sem(i,vales[i]);
        //信号量的编号 初始值
    }
    
    fork_ret=fork();
    if(fork_ret>0)
    {
        signal(SIGINT,signal_catch);
        
        //得到第二个子进程
        fork_ret=fork();
        if(fork_ret>0)
        {
            //父进程执行的代码
            //当信号量为0时进行p操作，semop的p操作会阻塞
            while(1)
            {
                p_sem(0);
                printf("000000\n");
                sleep(1);

                v_sem(1);
            }
        }

        else if(fork_ret==0)
        {
            //第二个子进程执行的代码
            while(1)
            {
                p_sem(2);
                printf("222222\n");
                sleep(1);

                v_sem(0);
            }
        }
    }
    
    //得到第一个子进程
    else if(fork_ret==0)
    {
        //第一个子进程执行的代码
        while(1)
        {
            p_sem(1);
            printf("111111\n");
            sleep(1);

            v_sem(2);
        }
    }
    
    return 0;
}
void get_sem(int sem_num)
{
    int semid;
    __key_t key;
    pid_t fd;
    
    key=ftok(".",'b');
    if(key==-1)
    {
        print_error("ftok fail");
    }
    semid=semget(key,sem_num,0664|IPC_CREAT);
    //key 指定信号量的个数 设置
    if(semid==-1)
    {
        print_error("semget fail");
    }
}
void print_error(char *str)
{
    printf(str);

    exit(-1);
}
void init_sem(int sem_num,int val)
{
    int ctl_ret;
    union semun sem_un;

    sem_un.val=val;
    ctl_ret=semctl(semid,sem_num,SETVAL,sem_un.val);
    //信号量标识符 信号量的编号 设置初始值 初始值 
    if(ctl_ret==-1)
    {
        print_error("semctl SETVAL error");
    }
}
void delete_sem(int sem_num_sem)
{
    int ret;

    /*
    ret=semctl(semid,0,IPC_RMID);
        //信号量标识符 信号量编号 删除信号量编号
        if(ret==-1)
        {
            print_error("semctl IPC_RMID error");
        }
    */
    
    for(sem_num=0;sem_num<sem_num_sum;sem_num++)
    {
        ret=semctl(semid,sem_num,IPC_RMID);
        //信号量标识符 信号量编号 删除信号量编号
        if(ret==-1)
        {
            print_error("semctl IPC_RMID error");
        }
    }
}
void signal_catch(int signal_index)
{
    delete_sem(NSEMS);

    exit(-1);
}
void p_sem(int sem_num)
{
    int ret=-1;
    struct sembuf sops;
    
    sops.sem_num=sem_num;
    sops.sem_op=-1;//p
    sops.sem_flg=SEM_UNDO;
    
    ret=semop(semid,&sops,1);
    //信号量集合标识符 pv 数组元素的个数
    if(ret==-1)
    {
        print_error("semop p fail");
    }
}
void v_sem(int sem_num)
{
    int ret;
    struct sembuf sops;
    
   
    sops.sem_num=sem_num;//信号量编号
    sops.sem_op=1;//v
    sops.sem_flg=SEM_UNDO;//

    ret=semop(semid,&sops,1);
    //信号量集合标识符 pv 数组元素的个数
    if(ret==-1)
    {
        print_error("semop v fail");
    }
}


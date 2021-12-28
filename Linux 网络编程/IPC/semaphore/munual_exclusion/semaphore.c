#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "semaphore.h"
#include <unistd.h>
#include<signal.h>

int sem_id;

int main(void)
{

    pid_t fork_ret;
    unsigned short semnums[1]={0},fd;
    //得到信号量集合
    sem_id=get_sem(NSEMS);

    //初始化
    for(int i=0;i<NSEMS;i++)
    {
        init_sem(sem_id,i,1);
    }
    //打开要写的文件
    fd=open("./file.txt",O_RDWR|O_CREAT|O_TRUNC,0664);
    if(fd==-1)
    {
        print_error("open fail");
    }

    //得到子进程
    fork_ret=fork();
    if(fork_ret>0)
    {
        signal(SIGINT,signal_catch);
        while(1)
        {
            p_sem(sem_id);
            write(fd,"hello ",6);
            write(fd,"world\n",6);
            
            sleep(1);
            v_sem(sem_id);
        }
    }
    else if(fork_ret==0)
    {
        while(1)
        {
            p_sem(sem_id);
            write(fd,"good  ",6);
            write(fd,"bye  \n",6);
            sleep(1);
            v_sem(sem_id);
        }
    }
    
    return 0;
}
int get_sem(int sem_num)
{
    int semid;
    __key_t key;
    pid_t fd;
    
    key=ftok(".",'s');
    if(key==-1)
    {
        print_error("ftok fail");
    }
    semid=semget(key,sem_num,0664|IPC_CREAT);
    //key 信号量集合的个数 设置
    if(semid==-1)
    {
        print_error("semget fail");
    }

    return semid;
}
void print_error(char *str)
{
    printf(str);

    exit(-1);
}
void init_sem(int sem_id,int sem_num,int val)
{
    int ret;
    union semun sem_un;

    sem_un.val=val;
    ret=semctl(sem_id,sem_num,SETVAL,sem_un.val);
    //信号量标识符 信号量的编号 设置初始值 初始值 
    if(ret==-1)
    {
        print_error("semctl SETVAL error");
    }
}
void delete_sem(int sem_id,int sem_num_sum)
{
    int sem_num,ret;
    
    for(sem_num=0;sem_num<sem_num_sum;sem_num++)
    {
        ret=semctl(sem_id,sem_num,IPC_RMID);
        //信号量标识符 信号量编号 删除信号量编号
        if(ret==-1)
        {
            print_error("semctl IPC_RMID error");
        }
    }
}
void signal_catch(int signal_index)
{
    delete_sem(sem_id,NSEMS);

    exit(-1);
}
void p_sem(int sem_id)
{
    int ret=-1;
    struct sembuf sops;
    
  
        sops.sem_num=0;
        sops.sem_op=-1;//p
        sops.sem_flg=SEM_UNDO;
    
    ret=semop(sem_id,&sops,1);
    //信号量集合标识符 pv 数组元素的个数
    if(ret==-1)
    {
        print_error("semop p fail");
    }
}
void v_sem(int sem_id)
{
    int ret;
    struct sembuf sops;
    
   
        sops.sem_num=0;//信号量编号
        sops.sem_op=1;//v
        sops.sem_flg=SEM_UNDO;//
     ret=semop(sem_id,&sops,1);
    //信号量集合标识符 pv 数组元素的个数
    if(ret==-1)
    {
        print_error("semop v fail");
    }
}
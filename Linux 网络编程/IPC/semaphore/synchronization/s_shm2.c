#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include<unistd.h>
#include<signal.h>
#include<errno.h>
#include <sys/sem.h>

#define FILE_NAME "./shm_file"
#define SHM_SIZE 4096

void get_shm();
void print_error(char *string);
void signal_catch(int signal_index);
int create_fifo(char *path_name,int mode);
//信号量
void get_sem(int sem_num);
void init_sem(int sem_num,int val);
void delete_sem(int sem_num_sem);
void p_sem(int sem_num);
void v_sem(int sem_num);

#define NSEMS 2
union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  array;  /* Array for GETALL, SETALL */
 };

int semid;

int shm_id=-1;
char buf[300]={"121448948944165489864156418941564189613255512389962165864841465\n"};
void *shmaddr=NULL;

int main(void)
{
    int fd;
    int ret;
    pid_t pid;
    int vales[2]={1,0};

    signal(SIGINT,signal_catch);
    
    get_shm();
    shmaddr=shmat(shm_id,NULL,0);
    if(shmaddr==(void *)-1)
    {
        print_error("shmat fail");
    }
    if(shmaddr==(void *)-1)
    {
        print_error("shmat fail");
    }
    //信号量
    get_sem(NSEMS);
    for(int i=0;i<NSEMS;i++)
    {
        init_sem(i,vales[i]);
        //信号量的编号 初始值
    }
    while(1)
    {

        /*memcpy指的是C和C++使用的内存拷贝函数，函数原型为void *memcpy(void *destin, void *source, unsigned n)；
        函数的功能是从源内存地址的起始位置开始拷贝若干个字节到目标内存地址中，即从源source中拷贝n个字节到目标destin中。*/
        //void *memcpy(void *dest, const void *src, size_t n);
        p_sem(1);
        printf("%s",(char *)shmaddr);
        bzero(shmaddr,SHM_SIZE);
        sleep(1);
        v_sem(0);
    }

    return 0;
}
void get_shm()
{
    int fd,ret;
    key_t key;

    fd=open(FILE_NAME,O_CREAT|O_RDWR,0664);
    if(fd==-1)
    {
        print_error("open fail");
    }
    key=ftok(FILE_NAME,'b');
    if(key==-1)
    {
        print_error("ftok fail");
    }
    shm_id=shmget(key,SHM_SIZE,0664|IPC_CREAT);
    if(shm_id==-1)
    {
        print_error("shmget fail");
    }
}
void print_error(char *string)
{
    perror(string);
    exit(-1);
}
void signal_catch(int signal_index)
{
    
    shmdt(shmaddr);
    shmctl(shm_id,IPC_RMID,NULL);
    remove(FILE_NAME);
    delete_sem(NSEMS);

    exit(-1);
}
//信号量
void get_sem(int sem_num)
{
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
    
    for(int sem_num=0;sem_num<sem_num_sem;sem_num++)
    {
        ret=semctl(semid,sem_num,IPC_RMID);
        //信号量标识符 信号量编号 删除信号量编号
        if(ret==-1)
        {
            print_error("semctl IPC_RMID error");
        }
    }
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

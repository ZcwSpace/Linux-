#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<signal.h>

//信号量集合当中信号量的个数
#define NSEMS 1

union semun {
    int              val;    /* 存放初始化信号量的值 */
    struct semid_ds buf;    /* 存放struct semid _s结构体变量的.. */
    unsigned short  array;  /* Array for GETALL, SETALL *///不做要求
    struct seminfo  __buf;  /* Buffer for IPC_INFO
                                               (Linux-specific) *///不做要求
 };

//信号量集合标识符
int bolts_id;

void print_error(char *str);
void getting_sem(int sem_num);
void init_sem(int id,int val);
void delete_sem();
void signal_catch(int signal_index);
void unlocking(int bolts_id);
void locking(int bolts_id);

int main(void)
{
    pid_t fork_ret;
    unsigned short semnums[1]={0};
    int fd;
    unsigned int i;

    getting_sem(NSEMS);

    for(i=0;i<NSEMS;i++)
    {
        init_sem(i,1);
    }

    //打开要写的文件
    fd=open("./file.txt",O_RDWR|O_CREAT|O_TRUNC,0664);
    if(-1==fd)
    {
        print_error("open fail");
    }
    /*
        父子进程共同使用由父进程打开的文件，写入数据时不加O_APPEND也不会相互覆盖。
        父子进程各自独立打开同一个文件，写入数据时不加O_APPEND会相互覆盖。
    */
    
    //得到子进程
    fork_ret=fork();//该函数会被调用两次，父进程返回子进程id，子进程返回0。
    if(fork_ret>0)
    {
        signal(SIGINT,signal_catch);
        while(1)
        {
            locking(bolts_id);
            write(fd,"hello ",6);
            write(fd,"world\n",6);
            sleep(1);
            unlocking(bolts_id);
        }
    }
    else if(0==fork_ret)
    {
        while(1)
        {
            locking(bolts_id);
            write(fd,"good  ",6);
            write(fd,"bye  \n",6);
            sleep(1);
            unlocking(bolts_id);
        }
    }
    
    return 0;
}

//获取信号量集合
void getting_sem(int sem_num)//信号量集合中信号量的个数
{
    __key_t key;
    
    //系统建立IPC通讯 （消息队列、信号量和共享内存） 时必须指定一个ID值。
    //通常情况下，该id值通过ftok函数得到。
    key=ftok(".",'s');//指定的文件名（已经存在的文件名），一般使用当前目录 子序号
    if(-1==key)
    {
        print_error("fail in ftok");
    }

    //根据key值获取信号量集合，并返回其标识符。
    bolts_id=semget(key,sem_num,0664|IPC_CREAT);//key 指定信号量集合当中信号量的个数 设置
    if(-1==bolts_id)
    {
        print_error("fail in semget");
    }
}

//出错处理
void print_error(char *str)//想要打印的信息
{
    perror(str);
    putchar('\n');

    exit(-1);
}

//初始化信号量集合
void init_sem(int id,int val)//信号量编号 初始值
{
    int ret;    
    union semun sem_un;
    
    sem_un.val=val;
    ret=semctl(bolts_id,id,SETVAL,sem_un.val);//信号量集合标识符 信号量的编号 设置初始值功能 初始值 
    if(-1==ret)
    {
        print_error("semctl SETVAL error");
    }
}

//删除信号量
void delete_sem()
{
    int ret;    

    ret=semctl(bolts_id,0,IPC_RMID);//信号量集合标识符 信号量编号 功能标志
    //删除的对象是信号量集合，和信号量编号没有关系。所以第二个参数没有用到，可以随意指定值。
    if(-1==ret)
    {
        print_error("semctl IPC_RMID error");
    }
}

//信号量捕获函数
void signal_catch(int signal_index)
{
    delete_sem();

    exit(-1);
}

//加锁
void locking(int bolts_id)
{
    int ret=-1;
    struct sembuf sops;
    
    sops.sem_num=0;//信号量编号
    sops.sem_op=-1;//p操作
    sops.sem_flg=SEM_UNDO;//防止死锁                  
    
    ret=semop(bolts_id,&sops,1);//信号量集合标识符 pv 数组元素的个数
    if(-1==ret)
    {
        print_error("semop p fail");
    }
}

//解锁
void unlocking(int bolts_id)
{
    int ret;
    struct sembuf sops;
    
    sops.sem_num=0;//信号量编号
    sops.sem_op=1;//v操作
    sops.sem_flg=SEM_UNDO;//当我们没有指定解锁操作时，让操作系统帮忙进行v操作。

    ret=semop(bolts_id,&sops,1);//防止死锁 
    if(-1==ret)
    {
        print_error("semop v fail");
    }
}

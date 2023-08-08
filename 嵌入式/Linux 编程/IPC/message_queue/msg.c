#include<stdlib.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<strings.h>
#include<signal.h>

#define MSG_FILE "./msg_file"
#define MSGSZ 1024

key_t get_queue(void);
void signal_catch(int signal_catch);
void gain_queue_properties( key_t msgid);


struct msgbuf 
{
               long mtype;       /* message type, must be > 0 */
               char mtext[MSGSZ];    /* message data */
};

static key_t msgid;

int main(int argc,char**argv)
{
    int ret=-1;

    msgid=get_queue();

    ret=fork();
    if(ret>0)
    {
        struct msgbuf msg_buf;

        //int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);
        while(1)
        {
            signal(SIGINT,signal_catch);
            //封装消息包
            scanf("%s",msg_buf.mtext);
            printf("input msgid\n");
            scanf("%ld",&msg_buf.mtype);

            //发送消息
            ret=msgsnd(msgid,&msg_buf,MSGSZ,0);
            if(ret==-1)
            {
                perror("msgsnd fail");
            }
            gain_queue_properties(msgid);
        }
        
    }
    else if(ret==0)
    {
        struct msgbuf msg_buf={0};
        long recv_msgtype=0;

        if(argc!=2)
        {
            printf("./msg msgtype\n");
            exit(-1);
        }

        //ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp,int msgflg);
        while(1)
        {
            ssize_t ret;

            bzero(msg_buf.mtext,MSGSZ);
            ret=msgrcv(msgid,&msg_buf,MSGSZ,atol(argv[1]),0);
            if(ret==-1)
            {
                perror("msgrcv fail");
            }
            printf("%s\n",msg_buf.mtext);
        }
    }
    

    return 0;
}
key_t get_queue(void)
{
    key_t key,msgid;
    
    open(MSG_FILE,O_RDWR|O_CREAT,0664);
    key=ftok(MSG_FILE,'a');
    if(key==-1)
    {
        perror("ftok faiol");
    }
    msgid=msgget(key, 0664|IPC_CREAT);
    if(msgid==-1)
    {
        perror("msgget faiol");
    }

    return msgid;

}
void signal_catch(int signal_catch)
{
    msgctl(msgid,IPC_RMID,NULL);
    exit(-1);
}
void gain_queue_properties( key_t msgid)
{
    struct msqid_ds buf;                                              
    
    msgctl(msgid,IPC_STAT,&buf);
    printf("队列中当前所有消息总的字节数%d",buf.__msg_cbytes);
}
#include "huffman.h"
//先进先出的线性表
typedef struct Queue
{
    char letter;
    int num;
    struct Queue * next;
}Node,*nodeAddr; 

typedef struct 
{
    nodeAddr front,rear;
}LinkQueue;

//初始化
void initializating(LinkQueue *link_queue_addr)
{
    //队列的头和尾都指向头结点
    link_queue_addr->front=link_queue_addr->rear=(LinkQueue*)malloc(sizeof(Node));
    if(!link_queue_addr->front)
    {
        exit(0);
    }
    //头结点的next指针设置为空
    link_queue_addr->front->next=NULL;
}
//增加
void adding(LinkQueue * q,char e,int num)
{
    nodeAddr node_addr;

    node_addr=(nodeAddr)malloc(sizeof(Node));
    if(!node_addr)
    {
        exit(0);
    }
    //为要新增的节点赋值
    node_addr->letter=e;
    node_addr->num=num;
    node_addr->next=NULL;
    
    q->rear->next=node_addr;
    q->rear=node_addr;
}

//删除
void deleting(LinkQueue *q)
{
    if(q->front==q->rear)
    {
        return;
    }
    
    nodeAddr node_addr;

    node_addr=q->front->next;
    q->front->next=node_addr->next;
    if(node_addr=q->rear)
    {
        q->rear=q->front;
    }
    free(node_addr);
}

//销毁队列
void destroying(LinkQueue *q)
{
    nodeAddr node_addr;

    while(q->front)
    {
        node_addr=q->front;
        q->front=node_addr->next;
        free(node_addr);
    }
}


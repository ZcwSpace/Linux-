#include <stdio.h>
#include <stdlib.h>


#define ELEMTYPE int
typedef struct QNode
{
	ELEMTYPE data;
	struct QNode *next;
}QNode,*QueuePrt;

typedef struct
{
	QueuePrt front, rear;
}LinkQueue;

void init_queue(LinkQueue *q);
void push_queue(LinkQueue *q,ELEMTYPE e);
void pop_queue(LinkQueue *q,ELEMTYPE* e);
void destory_queue(LinkQueue *q);

//初始化队列
void init_queue(LinkQueue *q)
{
	q->front = q->rear = (QueuePrt)malloc(sizeof(QNode));
	if (!q->front)
	{
		exit(0);
	}
	q->front->next = NULL;
}

//入队列
void push_queue(LinkQueue *q, ELEMTYPE e)
{
	QueuePrt p;

	p = (QueuePrt)malloc(sizeof(QNode));
	if (p == NULL)
	{
		exit(0);
	}
	p->data = e;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;
}

//出队列
void pop_queue(LinkQueue *q, ELEMTYPE* e)
{
	QueuePrt p;

	if (q->front ==q->rear)
	{
		return;
	}

	
	*e = q->front->next->data;

	p = q->front->next;
	q->front->next = p->next;
	if (q->rear == p)
	{
		q->rear = q->front;
	}

	free(p);
}

//销毁队列
void destory_queue(LinkQueue *q)
{
	while (q->front)
	{
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
	}
}

//判断
int QueueEmpty(LinkQueue *q)
{
	if(q->front != q->rear)
	{
		return 0;
	}
	return 1;
}
#include <stdio.h>
#include <stdlib.h> 

typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;

#define OK 1
#define ERROR 0
#define TURE 1
#define FALSE 0
typedef struct Node *LinkList;        
typedef int Status;//函数类型

Status GetElem(LinkList L,int i,ElemType *e);
void CreateList(LinkList *L);
Status ListInsert(LinkList *L,int i,ElemType e);

int main()
{
    LinkList Data;
    Status e;
    CreateList(&Data);
    ListInsert(&Data,1,2);
    GetElem(Data,1,&e);
    printf("%d",e);
}
void CreateList(LinkList *L)
{
    LinkList p;
    p=*L;
    p->data=1;
    p->next=NULL;
    
}
//读取
Status GetElem(LinkList L,int i,ElemType *e)
{
    //定义
    int j;
    LinkList p;
    
    //声明
    p=L->next;
    j=1;

    while(p&&j<i)
    {
        p=p->next;
        ++j;
    }
    
    if(!p||j>i)
    {
        return ERROR;
    }
    *e=p->data;
    return OK;
}
//插入
Status ListInsert(LinkList *L,int i,ElemType e)
{
    //定义
    int j;
    LinkList p,s;
    //声明
    p=*L;
    j=1;
    while(p&&j<i)
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i)
    {
        return ERROR;
    }
    s=(LinkList )malloc(sizeof(Node));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return OK;
}
//删除


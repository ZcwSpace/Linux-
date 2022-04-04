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
typedef int Status;//��������

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
//��ȡ
Status GetElem(LinkList L,int i,ElemType *e)
{
    //����
    int j;
    LinkList p;
    
    //����
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
//����
Status ListInsert(LinkList *L,int i,ElemType e)
{
    //����
    int j;
    LinkList p,s;
    //����
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
//ɾ��


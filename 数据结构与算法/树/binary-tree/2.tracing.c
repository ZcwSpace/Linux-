#include "1.node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void creating(NodeAddr node_addr);
void tracing(int floor,NodeAddr node_addr);

int main()
{
    Node node;

    creating(&node);
    tracing(1,&node);

    return 0;
}

//以前序遍历的顺序建立二叉树
void creating(NodeAddr node_addr)
{

    printf("请输入数据：");
    scanf("%c",&(node_addr->data));
    getchar();
    if('^'==node_addr->data)
    {
        free(node_addr);
        node_addr=NULL;
        return ;
    }
    node_addr->lchild=malloc(sizeof(Node));
    creating(node_addr->lchild);
    node_addr->rchild=malloc(sizeof(Node));
    creating(node_addr->rchild);
}

//前序遍历
void tracing(int floor,NodeAddr node_addr)
{
    if(NULL!=node_addr)
    {
        printf("%c在第%d层\n",node_addr->data,floor);
        tracing(floor,node_addr->lchild);
        tracing(floor,node_addr->rchild);
    }
}

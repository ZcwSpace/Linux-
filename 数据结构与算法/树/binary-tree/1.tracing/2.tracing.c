#include "1.node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void creating(NodeAddr *node_addr_addr);
void tracing(int floor,NodeAddr node_addr);

int main()
{
    NodeAddr nodeaddr;

    creating(&nodeaddr);
    putchar('\n');
    tracing(1,nodeaddr);

    return 0;
}

//用前序遍历的顺序建立二叉树
void creating(NodeAddr *node_addr_addr)
{
    char c;

    scanf("%c",&c);
    if('.'==c)
    {
        *node_addr_addr=NULL;
    }
    else
    {
        *node_addr_addr=(NodeAddr)malloc(sizeof(Node));
        (*node_addr_addr)->data=c;
        printf("%c",c);
        creating(&(*node_addr_addr)->lchild);
        creating(&(*node_addr_addr)->rchild);
    }
}

//前序遍历
void tracing(int floor,NodeAddr node_addr)
{
    if(node_addr)
    {
        printf("%c在第%d层\n",node_addr->data,floor);
        tracing(floor+1,node_addr->lchild);
        tracing(floor+1,node_addr->rchild);
    }
    
}

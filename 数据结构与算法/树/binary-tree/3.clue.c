#include <stdio.h>
#include <stdlib.h>

#define ElemType char //Element Type
enum{Link,Thread};
typedef struct  BiTNode//Binary Bree Node
{
    ElemType data;
    struct BiTNode *lchild,*rchild;//father node,left child,right child
    _Bool ltag,rtag;//标志指针的指向的对象：0：指向左或右孩子的指针；1：指向前驱或后继节点的指针
}Node,*NodeAddr;//,Node Address 

//全局变量，始终指向刚刚访问过的节点
NodeAddr pre=NULL;

void creating(NodeAddr *node_addr_addr);
void cueing1(NodeAddr *p,NodeAddr node_addr);
void outputing(NodeAddr p);

int main(void)
{
   NodeAddr p,node_addr;

    creating(&node_addr);
    cueing1(&p,node_addr);
    outputing(p);

    return 0;
}

//以前序遍历的顺序建立一颗二叉树
void creating(NodeAddr *node_addr_addr)
{
    char c;

    scanf("%c",&c);
    if('.'==c)
    {
        //将左或右孩子的指针设为空
        //怎么和它的双亲节点扯上关系？
        *node_addr_addr=NULL;
    }
    else
    {
        *node_addr_addr=(NodeAddr)malloc(sizeof(Node));
        (*node_addr_addr)->data=c;

        //先默认左右孩子都为0
        (*node_addr_addr)->ltag=Link;
        (*node_addr_addr)->rtag=Link;
        creating(&((*node_addr_addr)->lchild));
        creating(&((*node_addr_addr)->rchild));   
    }
}

void cueing2(NodeAddr node_addr);
void cueing1(NodeAddr *p,NodeAddr node_addr)
{
    (*p)=(NodeAddr)malloc(sizeof(Node));
    (*p)->ltag=Link;
    (*p)->rtag=Thread;
    
    if(!node_addr)
    {
        (*p)->lchild=(*p);
    }
    else
    {
        (*p)->lchild=node_addr;
        pre=(*p);

        cueing2(node_addr);
        
        pre->rchild=(*p);
        pre->rtag=Thread;
        (*p)->rchild=pre;
    }
}

//中序遍历:左子树->根节点->右子树
void cueing2(NodeAddr node_addr)
{
    if(node_addr)
    {
        cueing2(node_addr->lchild);//左子树

        if(!node_addr->lchild)
        {
            node_addr->ltag=Thread;
            node_addr->lchild=pre;
        }
        else if(!pre->rchild)
        {
            pre->rtag=Thread;
            pre->rchild=node_addr;
        }
        pre=node_addr;

        cueing2(node_addr->rchild);//右子树
    }
}
void outputing(NodeAddr p)
{
    NodeAddr node_addr=p->lchild;

    while(p!=node_addr)
    {
        //左子树
        while(node_addr->ltag!=Thread)
        {
            node_addr=node_addr->lchild;
        }

        printf("%c\n",node_addr->data);

        //右子树
        while(node_addr->rtag=Thread&&node_addr->rchild!=p)
        {
            node_addr=node_addr->rchild;
            printf("%c\n",node_addr->data);
        }

        node_addr=node_addr->rchild;
    }
}


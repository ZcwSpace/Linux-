#define ElemType char //Element Type
typedef struct  BiTNode//binary tree node
{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}Node,*NodeAddr;//,node address 

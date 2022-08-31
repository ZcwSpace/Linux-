#define ElemType char //Element Type
typedef struct  BiTNode//Binary Bree Node
{
    ElemType data;
    struct BiTNode *lchild,*rchild;//father node,left child,right child
}Node,*NodeAddr;//,Node Address 

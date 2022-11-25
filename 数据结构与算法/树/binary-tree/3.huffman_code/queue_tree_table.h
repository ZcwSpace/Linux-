
#include <huffman.h>

#define ElemType char //Element Type
//树和队列
typedef struct queue_tree
{
    ElemType data;//字母
    int num;//数量
    struct queue_tree *lchild,*rchild;//左子树 右子树
    struct queue_tree * next;//队列的下一个节点
}Node,*NodeAddr;

typedef struct 
{
    NodeAddr front,rear;
}LinkQueue;

//表
typedef struct table_node
{
    char letter;
    char * string;
    struct table_node * next; 
}Tb_Node,*Tb_Node_Addr;

typedef struct table
{
    struct table_node * first; 
    struct table_node * rear; 
}Tbl,*Tbl_addr;

void queue_inserting(LinkQueue * q,NodeAddr node_addr);
void creating(LinkQueue *q,NodeAddr node_addr);
void tracing_tree(int k,NodeAddr nodeaddr,char code[256],Tbl_addr table);
void initializating(LinkQueue *link_queue_addr);
void adding(LinkQueue * q,char e,int num);
void deleting(LinkQueue *q,NodeAddr node_addr);
void judging(LinkQueue * q,char e,int num);
void tracing_queue(LinkQueue * q);
void sorting(LinkQueue * q);
void adding_queue(LinkQueue * q,NodeAddr node_addr);

//用前序遍历的顺序建立二叉树
void creating(LinkQueue *q,NodeAddr node_addr)
{
    NodeAddr node_addr1,node_addr2,temp;

    node_addr1=(NodeAddr)malloc(sizeof(Node));
    node_addr2=(NodeAddr)malloc(sizeof(Node));
    deleting(q,node_addr1);
    deleting(q,node_addr2);

    temp=(NodeAddr)malloc(sizeof(Node));
    temp->num=node_addr1->num+node_addr2->num;
    temp->data='.';

    temp->lchild=node_addr1;
    temp->rchild=node_addr2;

    if(q->front==q->rear)
    {
        *node_addr=*temp;
        return;
    }
    
    //queue_inserting(q,node_addr);
    adding_queue(q,temp);
    putchar('\n');
    tracing_queue(q);
    putchar('\n');

    creating(q,node_addr);
}

//前序遍历
void tracing_tree(int k,NodeAddr nodeaddr,char code[256],Tbl_addr table)
{
    if(nodeaddr->lchild==NULL&&nodeaddr->rchild==NULL)
    {
        code[k]='\n';
        
        Tb_Node_Addr tbl_node_addr=(Tb_Node_Addr)malloc(sizeof(Tb_Node));
        tbl_node_addr->letter=nodeaddr->data;
        tbl_node_addr->string=code;
        tbl_node_addr->next=NULL;

        if(table->first==NULL)
        {
            table->first=tbl_node_addr;
            table->rear=tbl_node_addr;
        }
        else
        {
            table->rear->next=tbl_node_addr;
            table->rear=tbl_node_addr;
        }
    }
    else
    {
        code[k]='0';
        tracing_tree(k+1,nodeaddr->lchild,code,table);
        code[k]='1';
        tracing_tree(k+1,nodeaddr->rchild,code,table);
    }
}


//初始化队列
void initializating(LinkQueue *link_queue_addr)
{
    //队列的头和尾都指向头结点
    link_queue_addr->front=link_queue_addr->rear=(Node*)malloc(sizeof(Node));
    if(!link_queue_addr->front)
    {
        exit(0);
    }
    //头结点的next指针设置为空
    link_queue_addr->front->next=NULL;
}

//增加队列的节点
void adding(LinkQueue * q,char e,int num)
{
    NodeAddr Node_addr;

    Node_addr=(NodeAddr)malloc(sizeof(Node));
    if(!Node_addr)
    {
        exit(0);
    }
    //为要新增的节点赋值
    Node_addr->data=e;
    Node_addr->num=num;
    Node_addr->next=NULL;
    Node_addr->lchild=NULL;
    Node_addr->rchild=NULL;
    
    q->rear->next=Node_addr;
    q->rear=Node_addr;
}

//删除
void deleting(LinkQueue *q,NodeAddr node_addr)
{
    if(q->front==q->rear)
    {
        printf("队列已无数据！！！");
        
        exit(0);
    }
    NodeAddr Node_addr;

    Node_addr=q->front->next;
    *node_addr=*Node_addr;
    
    q->front->next=Node_addr->next;
    if(Node_addr==q->rear)
    {
        q->rear=q->front;
    }
    free(Node_addr);
}


//先遍历，有就加在上面，没有就添加新节点再加
void judging(LinkQueue * q,char e,int num)
{
    NodeAddr Node_addr;

    Node_addr=q->front->next;
    while(Node_addr!=NULL)
    {
        if(Node_addr->data==e)
        {
            Node_addr->num++;
            break;
        }
        Node_addr=Node_addr->next;
    }
    if(Node_addr==NULL)
    {
        adding(q,e,1);
    }
}
void tracing_queue(LinkQueue * q)
{
    NodeAddr Node_addr;

    Node_addr=q->front->next;

    while(Node_addr!=NULL)
    {
        printf("%c %d\n",Node_addr->data,Node_addr->num);
        Node_addr=Node_addr->next;
    }
}

void sorting(LinkQueue * q)
{
    NodeAddr i,j;
    char e;
    int num;
    NodeAddr node_addr1,node_addr2;
    
    i=q->front->next;
    while(i!=q->rear)
    {
        j=i->next;
        while(j!=NULL)
        {
            if(i->num>=j->num)
            {
                e=i->data;
                num=i->num;
                node_addr1=i->lchild;
                node_addr2=i->rchild;

                i->data=j->data;
                i->num=j->num;
                i->lchild=j->lchild;
                i->rchild=j->rchild;

                j->data=e;
                j->num=num;
                j->lchild=node_addr1;
                j->rchild=node_addr2;

            }
            j=j->next;
        }
        i=i->next;
    }
}

void queue_inserting(LinkQueue * q,NodeAddr node_addr)
{
    NodeAddr temp=q->front->next;

    while(temp->next!=NULL)
    {
        if(node_addr->num>=temp->num&&node_addr->num<temp->next->num)
        {
            node_addr->next=temp->next;
            temp->next=node_addr;
            return ;
        }
        temp=temp->next;
    }

    if(node_addr->num<q->front->next->num)
    {
        node_addr->next=q->front->next;
        q->front->next=node_addr;
    }
    else if(temp->next==NULL)
    {
        node_addr->next=temp->next;
        temp->next=node_addr;
    }
}
void adding_queue(LinkQueue * q,NodeAddr node_addr)
{
    NodeAddr temp;

    temp=q->front->next;
    node_addr->next=temp;
    q->front->next=node_addr;
    sorting(q);
}
struct table * create_tbl(NodeAddr nodeaddr)
{
    struct table *tbl =(struct table * )malloc(sizeof(struct table));
    tbl->first=tbl->rear=NULL;

    char code[256];
    int k=0;
    tracing_tree(k,nodeaddr,code,&tbl);

    return tbl;
}
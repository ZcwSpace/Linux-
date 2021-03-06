#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node * next;
}*p_node;

struct Node *initing_list();
void inputing_data(p_node node);
void outputing_data(p_node node);
void inserting_data(p_node node,int addr,int data);
int getting_list_length(p_node node);
void inserting_sorting(p_node node);
void deleting_node(p_node node,int addr);

int main(void)
{
    p_node node;

    node=initing_list();
    inputing_data(node);
    outputing_data(node);
    inserting_sorting(node);
    outputing_data(node);

    return 0;
}

//初始化链表
struct Node *initing_list()
{
    p_node node;

    node=malloc(sizeof(struct Node));
    node->next=NULL;

    return node;
}

//往链表里输入数据
void inputing_data(p_node node)
{
    int number,i=0;
    p_node new_node;

    printf("请输入第%d个数据（输入0结束输入）：",++i);
    scanf("%d",&number);

    while(number!=0)
    {
        new_node=malloc(sizeof(struct Node));
        new_node->data=number;
        new_node->next=NULL;
        node->next=new_node;
        node=new_node;
        
        printf("请输入第%d个数据：（输入0结束输入）",++i);
        scanf("%d",&number);
    }
}

//输出数据
void outputing_data(p_node node)
{
    node=node->next;

    while(node!=NULL)
    {
        printf("%d ",node->data);
        node=node->next;
    }
    printf("\n");
}

//插入数据，参数分别是：头结点地址 插入后新节点的位置 要插入的数据
void inserting_data(p_node node,int addr,int data)
{
    if(addr>getting_list_length(node)+1)
    {
        printf("因为要插入的位置超过现在的长度加1，所以不能插入。");

        exit(-1);
    }
    else if(addr<=0)
    {
        printf("因为要插入的位置过于小，所以不能插入。");

        exit(-1);
    }
    p_node new_node;

    new_node=malloc(sizeof(struct Node));
    new_node->data=data;

    for(int i=1;i!=addr;i++,node=node->next)
    {}
    new_node->next=node->next;
    node->next=new_node;
}
//获取链表的长度
int getting_list_length(p_node node)
{
    node=node->next;
    int i=0;

    while(node!=NULL)
    {
        i++;
        node=node->next;
    }

    return i;
}

//实现插入排序
void inserting_sorting(p_node node)
{
    p_node front_node,last_node;
    int i,j;
    //int flag=0;

    for(i=2,last_node=node->next->next;last_node!=NULL/*&&i<=getting_list_length(node)*/;i++)
    {
        for(j=1,front_node=node->next;j<i;front_node=front_node->next,j++)
        {
            if(last_node->data>=front_node->data)//由大到小排序
            {
                inserting_data(node,j,last_node->data);
                last_node=last_node->next;
                //flag=1;
                printf("要删除数据了,j=%d,i+1=%d\n",j,i+1);
                deleting_node(node,i+1);
                goto label;
            }
        }
        /*
        if(flag!=1)
        {
            last_node=last_node->next;
        }
        flag=0;*/
        last_node=last_node->next;
        label:;
    }
}
//删除数据，参数分别是：头结点地址 想要删除的节点的位置
void deleting_node(p_node node,int addr)
{
    if(addr>getting_list_length(node))
    {
        printf("要删除的位置超过链表的长度！\n");

        //exit(-1);
    }
    else if(addr<1)
    {
        printf("要删除的位置小于链表的长度！\n");

        exit(-1);
    }
    else
    {
        p_node front_node,last_node;
        int i;
    
        front_node=node;
        last_node=node->next;
        for(i=1;i!=addr;i++)
        {
            front_node=last_node;
            last_node=last_node->next;
        }
        front_node->next=last_node->next;
        free(last_node);
    }   
}
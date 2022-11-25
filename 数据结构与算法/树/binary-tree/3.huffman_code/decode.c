/*
build a priority queue 具有优先级的队列,优先级取决于在文本中各个字符出现的顺序，次数少的排在前面
build a huffmanTree 
build a huffmanTable
encode
decode
*/
//哈弗曼树：左子树用0来表示，右子树用1来表示
#include "queue_tree_table.h"

void statistic(LinkQueue *link_queue,char * filename);

int main(int argc,char **argv)
{
    LinkQueue* link_queue;
    NodeAddr nodeaddr;
    struct table* tb; 

    nodeaddr=(NodeAddr)malloc(sizeof(Node));
    link_queue=(LinkQueue *)malloc(sizeof(LinkQueue));
    
    initializating(link_queue);
    statistic(link_queue,argv[1]);
    creating(link_queue,nodeaddr);
    free(link_queue->front);
    free(link_queue);

    tb=create_tbl(nodeaddr);

    tracing_tree(1,nodeaddr);
}
void statistic(LinkQueue *link_queue,char * filename)
{
    FILE *fd;
    char ch;
    int i=0;

    fd=fopen(filename,"r");
    if(NULL==fd)
    {
        printf("要加密的文件并不存在！\n");

        exit(0);
    }
    while(EOF!=(ch=fgetc(fd)))
    {

        judging(link_queue,ch,1);
    }

    sorting(link_queue);

    tracing_queue(link_queue);
}


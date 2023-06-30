#include "Queue.h"

#define VertexType char
#define MAXVEX 9

typedef struct EdgeNode
{
    int adjvex;
    struct EdgeNode *next;
}EdgeNode;

typedef struct Node
{
    VertexType data;
    EdgeNode * firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct 
{
    AdjList adjList;
    int numVertexes, numEdges;
}GraphAdjList;

void CreateALGraph( GraphAdjList *G);
void Traverse(GraphAdjList *G);

int main()
{
    GraphAdjList G;

    CreateALGraph(&G);
    Traverse(&G);

    return 0;
}
void CreateALGraph( GraphAdjList *G)
{
    int i, j, k;
    EdgeNode *e;

    printf("请输入顶点数和边数：");
    scanf("%d, %d", &G->numVertexes,&G->numEdges);
    printf("边数为：%d,顶点数为：%d\n", G->numVertexes, G->numEdges);
    getchar();

    //读入顶点信息
    for(i = 0; i< G->numVertexes; i++)
    {
        printf("请输入第%d个顶点：", i+1);
        scanf("%c",&G->adjList[i].data);
        getchar();
        
        G->adjList[i].firstedge = NULL;
    }

    //读入边的信息
    for(k = 0; k < G->numEdges; k++)
    {
        printf("输入边(vi,vj)上的顶点序号：\n");
        scanf("%d, %d", &i, &j);

        e = (EdgeNode *) malloc(sizeof(EdgeNode));

        e->adjvex = j;
        e->next = G->adjList[i].firstedge;
        G->adjList[i].firstedge = e;

        e = (EdgeNode *) malloc(sizeof(EdgeNode));

        e->adjvex = i;
        e->next = G->adjList[j].firstedge;
        G->adjList[j].firstedge = e;
    }
    /*
    for(i = 0; i < MAXVEX; i++)
    {
        printf("%c：",G->adjList[i].data);
        for(e = G->adjList[i].firstedge; e != NULL; e = e->next)
        {
            printf("%c ",G->adjList[e->adjvex].data);
        }
        putchar('\n');
    }
    */
}
void Traverse(GraphAdjList *G)
{
    LinkQueue q;

    init_queue(&q);

    int visited[MAXVEX] = {0};
    int i;

    if(!visited[i])
    {
        printf("%c ",G->adjList[i].data);
        visited[i] = 1;
        push_queue(&q,i);

        EdgeNode *node_adder;

        while(!QueueEmpty(&q))
        {
            pop_queue(&q,&i);

            for(node_adder = G->adjList[i].firstedge; node_adder != NULL; node_adder = node_adder->next)
            {
                if(!visited[node_adder->adjvex])
                {
                    printf("%c ", G->adjList[node_adder->adjvex].data);
                    visited[node_adder->adjvex] = 1;
                    push_queue(&q,node_adder->adjvex);
                }
            }
        }

    }
    destory_queue(&q);
}
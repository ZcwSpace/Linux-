#include <stdio.h>

#define LENGTH 9
#define INFINITY 65535

typedef struct Matrix
{
    int numVertexes;
    char vertex[LENGTH];
    int arc[LENGTH][LENGTH];
}Matrix;


void ShortestPath_Dijkstra(Matrix G, int outset, int road[LENGTH], int vertex[LENGTH]);

int main()
{
    Matrix matrix = 
    {
        LENGTH,
        {'A','B','F','G','I','C','H','E','D'},
        {{0,10,11,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY},
        {10,0,INFINITY,16,12,18,INFINITY,INFINITY,INFINITY},
        {11,INFINITY,0,17,INFINITY,INFINITY,INFINITY,26,INFINITY},
        {INFINITY,16,17,0,INFINITY,INFINITY,19,INFINITY,24},
        {INFINITY,12,INFINITY,INFINITY,0,8,INFINITY,INFINITY,21},
        {INFINITY,18,INFINITY,INFINITY,8,0,INFINITY,INFINITY,22},
        {INFINITY,INFINITY,INFINITY,19,INFINITY,INFINITY,0,7,16},
        {INFINITY,INFINITY,26,INFINITY,INFINITY,INFINITY,7,0,20},
        {INFINITY,INFINITY,INFINITY,24,21,22,16,20,0}}
    };
    int road[LENGTH];
    int parent[LENGTH];
    int outset = 0;

    for(int i = 0; i < LENGTH; i++)
    {
        printf("%d.%c ", i, matrix.vertex[i]);
    }
    putchar('\n');
    printf("您想求出第几个节点到其它所有节点的最短路径？\n");
    scanf("%d", &outset);

    ShortestPath_Dijkstra(matrix, outset, road, parent);

    printf("走过的路径：\n");
    int j;
    for(int i = 0; i < LENGTH; i++)
    {
        printf("%c -> %c:", matrix.vertex[outset], matrix.vertex[i]);
        j = i;
        while(parent[j] != -1)
        {
            printf("%c ", matrix.vertex[parent[j]]);
            j = parent[j];
        }
        putchar('\n');
    }

    printf("\n%c节点到其它各个节点的最短路径：\n");
    for(int i = 0; i< matrix.numVertexes; i++)
    {
        if(i != outset)
        {
            printf("%c -》%c : %d\n", matrix.vertex[outset], matrix.vertex[i], road[i]);
        }
        
    }

    return 0;
}

void ShortestPath_Dijkstra(Matrix G, int outset, int road[LENGTH], int parent[LENGTH])
{  
    int in[LENGTH];
    //将第一个节点加入生成树中，并将第一个节点与其它节点的关系存入power数组中
    for(int i = 0; i < G.numVertexes; i++)
    {
        road[i] = G.arc[outset][i];
        parent[i] = -1;
        in[i] = 0;
    }
    in[outset] = 1;
    road[outset] = 0;
    //从第一个节点开始遍历与其邻接的节点
    for(int i = 1; i < G.numVertexes; i++)
    {
        int min = INFINITY;
        int j = 0;
        int k;

        //查询与当前节点邻接的节点之间中权值最小的边。
        while(j < G.numVertexes)
        {
            if(!in[j] && road[j] < min)
            {
                min = road[j];
                k = j;
            }
            j++;
        }
        in[k] = 1;

        for(j = 0; j < G.numVertexes; j++)
        {
            if(!in[j] && (min + G.arc[k][j]) < road[j])
            {
                road[j] = G.arc[k][j] + min;
                parent[j] = k;
            }
        }

    }
}
/*
源点到各顶点的最短路径长度为:
A -》B : 10
A -》F : 11
A -》G : 26
A -》I : 22
A -》C : 28
A -》H : 44
A -》E : 37
A -》D : 43

v0 - v1 : 10 
v0 - v2 : 28 
v0 - v3 : 43 
v0 - v4 : 37 
v0 - v5 : 11 
v0 - v6 : 26 
v0 - v7 : 44 
v0 - v8 : 22 
*/
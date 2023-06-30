#include <stdio.h>

#define LENGTH 9
#define INFINITY 65535

typedef struct Matrix
{
    int numVertexes;
    char vertex[LENGTH];
    int arc[LENGTH][LENGTH];
}Matrix;

void MiniSpanTree_Prim(Matrix G);
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

    MiniSpanTree_Prim(matrix);

    return 0;
}
void MiniSpanTree_Prim(Matrix G)
{
    int adjvex[LENGTH];//保存相邻顶点的下标
    int lowcost[LENGTH];//保存相邻节点间边的权值

    lowcost[0] = 0;//先把A加入到最小生成树中，它的权值为0
    adjvex[0] = 0;//A第一个加入

    //初始化操作
    for(int i = 1; i< G.numVertexes; i++)
    {
        lowcost[i] = G.arc[0][i];
        adjvex[i] = 0;
    }
}
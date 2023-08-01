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
    int min, i, j, k;
    int adjvex[LENGTH];//保存相关顶点下标，如果节点和当前节点有联系，就在代表该节点的位置处填当前节点的位置。
    int lowcost[LENGTH];//保存相关顶点间边的权值

    lowcost[0] = 0;//v0作为最小生成树的跟开始遍历，权值为0
    adjvex[0] = 0;//v0第一个加入

    //初始化操作
    for(i = 0; i < G.numVertexes; i++)
    {
        lowcost[i] = G.arc[0][i];//将邻接矩阵第0行所有权值先加入数组
        adjvex[i] = 0;//初始化全部先为V0的下标
    }

    //真正构造最小生成树的过程
    for(i = 1; i < G.numVertexes; i++)
    {
        min = INFINITY; //初始化最小权值为65535等不可能达到的数值；
        j = 1;
        k = 0;

        //遍历全部顶点，找出最小权值
        while(j < G.numVertexes)
        {
            //找出lowcost数组已存储的最小权值
            if(lowcost[j] != 0 && lowcost[j] < min)
            {
                min = lowcost[j];//将发现的最小权值的下标存入k，以待使用
                k = j;
            }
            j++; 
        }
        //打印当前顶点边中权值最小的边
        printf("(%c, %c)",G.vertex[adjvex[k]], G.vertex[k]);
        lowcost[k] = 0; //将当前顶点的权值设置为0，表示此顶点已经完成任务，进行下一个顶点的遍历

        //邻接矩阵k行逐个遍历全部顶点
        for(j = 1; j < G.numVertexes; j++)
        {
            if(lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
            {
                lowcost[j] = G.arc[k][j];
                adjvex[j] = k;
            }
        }
    }
    putchar('\n');
}
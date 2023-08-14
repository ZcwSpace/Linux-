#include <stdio.h>

#define LENGTH 9
#define INFINITY 65535
#define MAXEDGE 15

typedef struct Matrix
{
    int numVertexes;
    char vertex[LENGTH];
    int arc[LENGTH][LENGTH];
}Matrix;

void MiniSpanTree_Kruskal(Matrix G);

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

    MiniSpanTree_Kruskal(matrix);

    return 0;
}

//对边集数组的定义
typedef struct 
{
    int begin;
    int end;
    int weight;
}Edge;

void sorting(Edge edges[]);
int finding(int in[], int f);

void MiniSpanTree_Kruskal(Matrix G)
{
    int i, j, k = 0, m;
    //定义边集数组
    Edge edges[MAXEDGE];
    //用来判断是否形成环路
    int in[LENGTH];

    //将邻接矩阵转为边集数组
    for(i = 0; i < LENGTH - 1; i++)
    {
        for(j = i + 1; j < LENGTH; j++)
        {
            if(G.arc[i][j] < INFINITY)
            {
                edges[k].begin = i;
                edges[k].end = j;
                edges[k].weight = G.arc[i][j];
                k++; 
            }
        }
    }

    //对边集数组进行排序
    sorting(edges);

    //初始化in数组
    for(int i = 0; i < LENGTH; i++)
    {
        in[i] = 0;
    }

    //循环每一条边，输出最小生成树
    for(i = 0; i < MAXEDGE; i++)
    {
        k = finding(in, edges[i].begin);
        m = finding(in, edges[i].end);

        if(k != m)
        {
            in[k] = m;
            printf("(%c, %c) %d", G.vertex[edges[i].begin], G.vertex[edges[i].end], edges[i].weight);
        }
    }
    putchar('\n');
}

void sorting(Edge edges[])
{
    int i, j;
    Edge temp;

    for(int i = 0; i < MAXEDGE - 1; i++)
    {
        for(int j = i + 1; j< MAXEDGE; j++)
        {
            if(edges[i].weight > edges[j].weight)
            {
                temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    //输出权值由小到大排序的结果
    for(i = 0; i < MAXEDGE; i++)
    {
        printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
    }
}

int finding(int in[], int f)
{
    while(in[f] > 0)
    {
        f = in[f];
    }

    return f;
}
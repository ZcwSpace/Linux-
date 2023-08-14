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
    int power[LENGTH];
    int addr[LENGTH];
   
    //将第一个节点加入生成树中，并将第一个节点与其它节点的关系存入power数组中
    for(int i = 0; i < G.numVertexes; i++)
    {
        power[i] = G.arc[0][i];
        addr[i] = 0;
    }

    //从第一个节点开始遍历与其邻接的节点
    for(int i = 1; i < G.numVertexes; i++)
    {
        int min = INFINITY;
        int j = 1;
        int k;

        //查询与当前节点邻接的节点之间中权值最小的边。
        while(j < G.numVertexes)
        {
            if(power[j] != 0 && power[j] < min)
            {
                min = power[j];
                k = j;
            }
            j++;
        }

        printf("(%c,%c)", G.vertex[addr[k]], G.vertex[k]);

        power[k] = 0;

        for(j = 1; j < G.numVertexes; j++)
        {
            if(power[j] != 0 && G.arc[k][j] < power[j])
            {
                power[j] = G.arc[k][j];
                addr[j] = k;
            }
        }

    }
    putchar('\n');
}
//(A, B)(A, F)(B, I)(I, C)(B, G)(G, H)(H, E)(H, D)
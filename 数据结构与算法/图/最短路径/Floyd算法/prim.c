#include <stdio.h>

#define LENGTH 9
#define INFINITY 65535

typedef struct Matrix
{
    int numVertexes;
    char vertex[LENGTH];
    int arc[LENGTH][LENGTH];
}Matrix;


void ShortestPath_Floyd(Matrix G, int road[LENGTH][LENGTH], int parent[LENGTH][LENGTH]);

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
    int road[LENGTH][LENGTH];
    int parent[LENGTH][LENGTH];
    int i, j, k;

    ShortestPath_Floyd(matrix, road, parent);

    printf("详细路径:\n");
    for(i = 0; i < matrix.numVertexes; i++)
    {
        for(j = i + 1; j < matrix.numVertexes; j++)
        {
            printf("%d-%d weight：%d path：%d", i, j, road[i][j], i);

            k = i;
            do
            {
                k = parent[k][j];
                printf(" -> %d",k);
            } while (k != j);
            putchar('\n');
        }
        putchar('\n');
    }

    printf("\n前驱节点：\n");
    for(i = 0; i < matrix.numVertexes; i++)
    {
        printf("%d: ",i);
        for(j =0; j < matrix.numVertexes; j++)
        {
            printf("%d ", parent[i][j]);
        }
        putchar('\n');
    }

    printf("\n最短路径：\n");
    for(i = 0; i < matrix.numVertexes; i++)
    {
        printf("%d: ",i);
        for(j =0; j < matrix.numVertexes; j++)
        {
            printf("%d ", road[i][j]);
        }
        putchar('\n');
    }

    return 0;
}

void ShortestPath_Floyd(Matrix G, int road[LENGTH][LENGTH], int parent[LENGTH][LENGTH])
{  
    int i, j, k;

    //初始化road与parent
    for(i = 0; i < G.numVertexes; i++)
    {
        for(j = 0; j < G.numVertexes; j++)
        {
            road[i][j] = G.arc[i][j];
            parent[i][j] = j;
        }
    }

    //修正
    for(i = 0; i < G.numVertexes; i++)
    {
        for(j = 0; j < G.numVertexes; j++)
        {
            for(k = 0; k < G.numVertexes; k++)
            {
                if(road[j][k] > road[j][i] + road[i][k])
                {
                    road[j][k] = road[j][i] + road[i][k];
                    parent[j][k] = parent[j][i];
                }
            }
        }
    }
}


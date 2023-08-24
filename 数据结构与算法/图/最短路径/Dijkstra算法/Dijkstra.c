#include <stdio.h>

#define LENGTH 9
#define INFINITY 65535
typedef int Patharc[LENGTH];    /* 用于存储最短路径下标的数组 */
typedef int ShortPathTable[LENGTH];/* 用于存储到各点最短路径的权值和 */

typedef struct Matrix
{
    int numVertexes;
    char vertex[LENGTH];
    int arc[LENGTH][LENGTH];
}Matrix;

void ShortestPath_Dijkstra(Matrix G, int v0, Patharc *P, ShortPathTable *D);

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

    ShortestPath_Dijkstra(matrix, 0, );

    
    return 0;
}

void ShortestPath_Dijkstra(Matrix G, int v0, Patharc *P, ShortPathTable *D)
{

}
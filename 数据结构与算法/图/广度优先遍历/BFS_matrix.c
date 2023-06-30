//邻接矩阵的广度遍历算法。
#include "Queue.h"

typedef struct Matrix
{
    int numVertexes;
    char vertex[9];
    int arc[9][9];
}Matrix;

int visited[9] = {0};

void BFS_traverse(Matrix M);

int main()
{
    Matrix m={9,\
    {'A', 'B', 'F', 'C', 'I', 'G', 'E', 'D', 'H'},\
    {{0, 1, 1, 0, 0, 0, 0, 0, 0},\
    {0, 0, 0, 1, 1, 1, 0, 0, 0},\
    {0, 0, 0, 0, 0, 1, 1, 0, 0},\
    {0, 0, 0, 0, 0, 0, 0, 1, 0},\
    {0, 0, 0, 0, 0, 0, 0, 1, 0},\
    {0, 0, 0, 0, 0, 0, 0, 1, 1},\
    {0, 0, 0, 0, 0, 0, 0, 1, 1},\
    {0, 0, 0, 0, 0, 0, 0, 0, 0},\
    {0, 0, 0, 0, 0, 0, 0, 0, 0}}};

    BFS_traverse(m);

    return 0;
}

void BFS_traverse(Matrix M)
{
    LinkQueue q;

    init_queue(&q);

    int i = 0, j;

    if(!visited[i])
    {
        printf("%c ",M.vertex[i]);
        visited[i] = 1;
        push_queue(&q, i);

        while(!QueueEmpty(&q))
        {
            pop_queue(&q,&i);
            //printf("\n取出来的值为：%d\n",i);

            for(j = 0; j < M.numVertexes; j++)
            {
                if(M.arc[i][j] == 1 && !visited[j])
                {
                    printf("%c ",M.vertex[j]);
                    visited[j] = 1;
                    push_queue(&q, j);
                }
            }
        }
    }


}
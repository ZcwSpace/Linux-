#include <stdio.h>   //printf所需的.h
#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE * p= fopen(".\\file.txt", "t");
    if(NULL == p)
    {
            perror("fopen error"); 
            exit(-1); //直接终止进程
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define SCALE  8

void judging(int record[SCALE][SCALE],int i,int j,int num);
void printing(int record[SCALE][SCALE]);

int main()
{                     
    int record[SCALE][SCALE]={0};
    int i,j;

    judging(record,2,0,0);

    return 0;
}

void judging(int record[SCALE][SCALE],int i,int j,int num)
{
    int record_temp[SCALE][SCALE];

    for(int i=0;i<SCALE;i++)
    {
        for(int j=0;j<SCALE;j++)
        {
            record_temp[i][j]=record[i][j];
        }
    }


    if(i<0||j<0||j>SCALE-1||i>SCALE-1)
    {
        return ;
    }
    else if(record_temp[i][j]==0)
    {
        record_temp[i][j]=++num;
        if(num==SCALE*SCALE)
        {
            printing(record_temp);
            exit(0);
        }
        judging(record_temp,i+1,j+2,num);
        judging(record_temp,i+1,j-2,num);
        judging(record_temp,i-1,j+2,num);
        judging(record_temp,i-1,j-2,num);

        judging(record_temp,i+2,j+1,num);
        judging(record_temp,i-2,j+1,num);
        judging(record_temp,i+2,j-1,num);
        judging(record_temp,i-2,j-1,num);
    }
}

void printing(int record[SCALE][SCALE])
{
    for(int i=1;i<=SCALE*SCALE;i++)
    {
        for(int j=0;j<SCALE;j++)
        {
            for(int k=0;k<SCALE;k++)
            {
                if(i == record[j][k])
                {
                    printf("%d\t",j*SCALE+k+1);
                }
            }
        }
        if(i%SCALE==0)
        {
            putchar('\n');
        }
    }
}

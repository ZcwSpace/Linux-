#include <stdio.h>
#include <stdlib.h>
#define SCALE  4

void judging(int record[SCALE][SCALE],int i,int j);

int main()
{                     
    int record[SCALE][SCALE]={0};
    int i,j;

    judging(record,2,0);

    return 0;
}

void judging(int record[SCALE][SCALE],int i,int j)
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
    else if(record_temp[i][j]!=1)
    {
        record_temp[i][j]=1;
        printf("我当前在%d位置！\n",i*SCALE+j+1);
        judging(record_temp,i+1,j+2);
        judging(record_temp,i+1,j-2);
        judging(record_temp,i-1,j+2);
        judging(record_temp,i-1,j-2);

        judging(record_temp,i+2,j+1);
        judging(record_temp,i-2,j+1);
        judging(record_temp,i+2,j-1);
        judging(record_temp,i-2,j-1);
    }
}

#include <stdio.h>
#include <stdlib.h>

int num=0;

void judging(char str[10][10],int i,int j,int record[10][10]);

int main()
{
    char str[10][10]={"UDDLUULRUL","UURLLLRRRU","RRUURLDLRD","RUDDDDUUUU","URUDLLRRUU","DURLRLDLRL",\
    "ULLURLLRDU","RDLULLRDDD","UUDDUDUDLL","ULRDLUURRR"};
    int record[10][10];
    int i,j;

    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            switch (str[i][j])
            {
            case 'U':
            judging(str,i-1,j,record);
                break;
            case 'D':
            judging(str,i+1,j,record);
                break;
            case 'L':
            judging(str,i,j-1,record);
                break;
            case 'R':
            judging(str,i,j+1,record);
                break;
            }
        }
    }
    printf("走出迷宫的人数为：%d\n",num);

    return 0;
}

void judging(char str[10][10],int i,int j,int record[10][10])
{
    int record_temp[10][10];

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            record_temp[i][j]=record[i][j];
        }
    }


    if(i<0||j<0||j>9||i>9)
    {
        num++;
    }
    else if(record_temp[i][j]!=1)
    {
        record_temp[i][j]=1;
        switch (str[i][j])
            {
            case 'U':
            judging(str,i-1,j,record_temp);
                break;
            case 'D':
            judging(str,i+1,j,record_temp);
                break;
            case 'L':
            judging(str,i,j-1,record_temp);
                break;
            case 'R':
            judging(str,i,j+1,record_temp);
                break;
            }
    }
}

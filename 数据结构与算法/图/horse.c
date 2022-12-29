#include <stdio.h>
#include <time.h>
#define SCALE  6

int judging(int i,int j,int num);
void printing();

int record[SCALE][SCALE]={0};

int main()
{                     
    clock_t start,finish;//定义两个变量记录开始和结束时间
    start=clock();

    judging(2,0,0);

    finish=clock();
    printf("本次计算一共耗时%f秒\n\n",(double)(finish-start)/CLOCKS_PER_SEC);
    //CLOCKS_PER_SEC:每秒运行多少个周期。
    //用一共运行多少回除以每秒运行多少周期就可以计算出运行了多少秒

    return 0;
}

int judging(int i,int j,int num)
{
    int flag=0;

    if(i<0||j<0||j>SCALE-1||i>SCALE-1)
    {
        return 0;
    }
    else if(record[i][j]==0)
    {
        record[i][j]=++num;
        if(num==SCALE*SCALE)
        {
            printing();
        }
        flag+=judging(i+1,j+2,num);
        flag+=judging(i+1,j-2,num);
        flag+=judging(i-1,j+2,num);
        flag+=judging(i-1,j-2,num);

        flag+=judging(i+2,j+1,num);
        flag+=judging(i-2,j+1,num);
        flag+=judging(i+2,j-1,num);
        flag+=judging(i-2,j-1,num);

        if(flag==0)
        {
            record[i][j]=0;
            return 0;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

//打印棋盘
void printing()
{
    int i,j,k;

    for(i=0;i<SCALE;i++)
    {
        for(j=0;j<SCALE;j++)
        {
            printf("%d\t",record[i][j]); 
        }
        putchar('\n');
    }
    putchar('\n');
}
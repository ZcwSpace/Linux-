#include <stdio.h>
#include <time.h>

#define X 6
#define Y 6

int chess[X][Y];
int TravelChessBoard(int x,int y,int tag);

int main()
{
    clock_t start,finish;//定义两个变量记录开始和结束时间
    start=clock();

    if(!TravelChessBoard(2,0,1))
    {
        printf("遍历失败！！！\n");
    }

    finish=clock();
    printf("本次计算一共耗时%f秒\n\n",(double)(finish-start)/CLOCKS_PER_SEC);
    //CLOCKS_PER_SEC:每秒运行多少个周期。
    //用一共运行多少回除以每秒运行多少周期就可以计算出运行了多少秒


    return 0;
}

int nextxy(int *x,int *y,int count);
void printing(int record[X][Y]);

//遍历棋盘
int TravelChessBoard(int x,int y,int tag)// 2 0 1
{
    int x1=x,y1=y,flag=0,count=0;

    chess[x][y]=tag;
    if(tag == X*Y)//判断是否已经走完了整个棋盘
    {
        printing(chess);

        return 1;
    }

    //找到马可以走的第一个坐标
    flag=nextxy(&x1,&y1,count);

    while(flag==0&& count<7)
    {
        count++;
        flag=nextxy(&x1,&y1,count);
    }
    while(flag)
    {
        if(TravelChessBoard(x1,y1,tag+1))
        {
            return 1;
        }

        //继续找到马的其它所有的下一步可走的其它的坐标
        x1=x;
        y1=y;
        count++;
        flag=nextxy(&x1,&y1,count);
        while(flag==0&& count<7)
        {
            count++;
            flag=nextxy(&x1,&y1,count);
        }
    }
    if(flag==0)
    {
        chess[x][y]=0;
    }

    return 0;
}

//判断下一个位置是否可走
int nextxy(int *x,int *y,int count)
{
    switch(count)
    {
        case 0:
        if(*x+2<X&&*y-1>=0&&chess[*x+2][*y-1] == 0)
        {
            *x+=2;
            *y-=1;
            
            return 1;
        }
        break;  

        case 1:
        if(*x+2<X&&*y+1<Y && chess[*x+2][*y+1] == 0)
        {
            *x+=2;
            *y+=1;
            
            return 1;
        }
        break;  

        case 2:
        if(*x-2>=0&&*y+1<Y && chess[*x-2][*y+1] == 0)
        {
            *x-=2;
            *y+=1;
            
            return 1;
        }
        break;  

        case 3:
        if(*x-2>=0&&*y-1>=0 && chess[*x-2][*y-1] == 0)
        {
            *x-=2;
            *y-=1;
            
            return 1;
        }
        break;  

        case 4:
        if(*x+1<X&&*y+2<Y && chess[*x+1][*y+2] == 0)
        {
            *x+=1;
            *y+=2;
            
            return 1;
        }
        break;  

        case 5:
        if(*x+1<X&&*y-2>=0 && chess[*x+1][*y-2] == 0)
        {
            *x+=1;
            *y-=2;
            
            return 1;
        }
        break;  

        case 6:
        if(*x-1>=0&&*y+2<Y && chess[*x-1][*y+2] == 0)
        {
            *x-=1;
            *y+=2;
            
            return 1;
        }
        break; 

        case 7:
        if(*x-1>=0&&*y-2>=0 && chess[*x-1][*y-2] == 0)
        {
            *x-=1;
            *y-=2;
            
            return 1;
        }
    }

    return 0;
}

//打印棋盘
void printing(int record[X][Y])
{
    int i,j,k;

    for(i=0;i<X;i++)
    {
        for(j=0;j<Y;j++)
        {
            printf("%d\t",record[i][j]); 
        }
        putchar('\n');
    }
}




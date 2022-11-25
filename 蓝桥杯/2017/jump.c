#include <stdio.h>

void jumping(int addr,int a[9],int num);
int judging(int a[9]);
void printing(int a[9]);
void w_file(int a[9]);
int  r_file(int a[9]);

FILE* fid;
int main()
{
    int a[9]={1,2,3,4,5,6,7,8,0};

    fid=fopen("./file.txt","w+");

    jumping(8,a,0);//零所在的位置 数组 步数

    fclose(fid);

    return 0;
}

//实现跳跃
void jumping(int addr,int a[9],int num)
{
    //检查是否已经有过遍历
    if(1==r_file(a))
    {
        return ;
    }
    //判断是否已经达到了终点
    if(1==judging(a))
    {
        printf("当前步数为：%d\n",num);
        printing(a);
    }
    else
    {
        if(num==21)
        {
            return ;
        }
        int temp;
        int temp1[9],temp2[9],temp3[9],temp4[9];

        for(int i=0;i<9;i++)
        {
            temp1[i]=temp2[i]=temp3[i]=temp4[i]=a[i];
        }

        //往前跳
        if(0==addr)
        {
            temp=temp1[addr];
            temp1[addr]=temp1[8];
            temp1[8]=temp;

            jumping(8,temp1,num+1);
        }
        else
        {
            temp=temp1[addr];
            temp1[addr]=temp1[addr-1];
            temp1[addr-1]=temp;


            jumping(addr-1,temp1,num+1);
        }
        
        //往后跳
        if(8==addr)
        {
            temp=temp2[addr];
            temp2[addr]=temp2[0];
            temp2[0]=temp;

            jumping(0,temp2,num+1);
        }
        else
        {
            temp=temp2[addr];
            temp2[addr]=temp2[addr+1];
            temp2[addr+1]=temp;

            jumping(addr+1,temp2,num+1);
        }

        //往前隔一个跳
        if(0==addr)
        {
            temp=temp3[addr];
            temp3[addr]=temp3[7];
            temp3[7]=temp;

            jumping(7,temp3,num+1);
        }
        else if(1==addr)
        {
            temp=temp3[addr];
            temp3[addr]=temp3[8];
            temp3[8]=temp;

            jumping(8,temp3,num+1);
        }
        else
        {
            temp=temp3[addr];
            temp3[addr]=temp3[addr-2];
            temp3[addr-2]=temp;

            jumping(addr-2,temp3,num+1);
        }
        
        //往后隔一个跳
        if(8==addr)
        {
            temp=temp4[addr];
            temp4[addr]=temp4[1]; 
            temp4[1]=temp;

            jumping(1,temp4,num+1);
        }
        else if(7==addr)
        {
            temp=temp4[addr];
            temp4[addr]=temp4[0];
            temp4[0]=temp;

            jumping(0,temp4,num+1);
        }
        else
        {
            temp=temp4[addr];
            temp4[addr]=temp4[addr+2];
            temp4[addr+2]=temp;

            jumping(addr+2,temp4,num+1);
        }
    } 
}

int judging(int a[9]) 
{
    int temp[8];

    for(int i=0;i<8;i++)
    {
        temp[i]=8-i;
    }

    int count;
    for(int i=0;i<9;i++)
    {
        for(count=0;temp[count]==a[i]&&count!=8;)
        {
            count++;
            if(i==8)
            {
                i=0;
            }
            else
            {
                i++;
            }
        }
        if(count==8)
        {
            return 1;
        }
        else if(count>0)
        {
            w_file(a);

            return 0;
        }
    }
}

void printing(int a[9])
{
        for(int i=0;i<9;i++)
        {
            printf("%d ",a[i]);
        }
        putchar('\n');
}

void w_file(int a[9])
{
    fseek(fid,0,SEEK_END);
    fwrite(a,4,9,fid);
}

int r_file(int a[9])
{
    int temp[9];
    int i;

    fseek(fid,0,SEEK_SET);   
    while(fread(temp,4,9,fid)==9)
    {
        for(i=0;i<9;)
        {
            if(temp[i]==a[i])
            {
                i++;
            }
            else
            {
                break;
            }
        }
        if(i==9)
        {
            return 1;
        }    
    }

    return 0;
}
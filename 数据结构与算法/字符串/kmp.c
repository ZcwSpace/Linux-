#include <stdio.h>
#include <stdlib.h>
#include <string.h>  

void matching(char main_str[],char child_str[]);

int main(void)
{
    int length;
    char element;
    
    //输入主串
    printf("请您要输入的主串的长度：");
    scanf("%d",&length);

    char main_str[length+1];
    main_str[0]=length;
    for(int i=1;i<=length;i++)
    {
        printf("请输入主串的第%d个元素：",i);
        getchar();
        scanf("%c",&main_str[i]);
        putchar('\0');
    }

    //输入子串
    printf("请您要输入的子串的长度：");
    scanf("%d",&length);

    char child_str[length+1];
    child_str[0]=length;
    for(int i=1;i<=length;i++)
    {
        printf("请输入主串的第%d个元素：",i);
        getchar();
        scanf("%c",&child_str[i]);
        putchar('\0');
    }

    matching(main_str,child_str);

    return 0;
}

//实现kmp算法
void getting_next(char target[],int next[]);
void matching(char main_str[],char child_str[])
{
    int next[child_str[0]+1];
    
    next[0]=child_str[0];
    //实现next数组
    getting_next(child_str,next);
    //打印next数组
    printf("next数组的元素为：");
    for(int i=1;i<=next[0];i++)
    {
        printf("%d ",next[i]);
    }
    putchar('\n');

    for(int i=1;i<=main_str[0];i++)
    {
        for(int j=i;j<=child_str[0];)
        {
           
            if(0==j&&i==main_str[0])
            {
                printf("Don't find!\n");
                exit(0);
            }
            if(main_str[i]==child_str[j]||0==j)
            {
                printf("match:%c\n",main_str[i]);
                i++;
                j++;
            }
            else
            {
                printf("don't match:%c\n",main_str[i]);
                j=next[j];
                continue;
            }
        }
    }
    printf("Find!\n");
}

//kmp算法的核心就是避免不必要的回溯。
//具体回溯多少由子串的元素决定。
//前一个元素是否匹配决定后一个元素回溯多少。
void getting_next(char child_str[],int next[])
{
    next[1]=0;
    int count,i,sum;

    for(int j=2;j<=child_str[0];j++)
    {
        count=0;
        i=1;
        sum=0;
        for(int k=i+1;k<j;k++)
        {
            if(child_str[k]==child_str[i])
            {
                count++;
                i++;
            }
            else
            {
                if(count>=sum)
                {
                    sum=count;
                    next[j]=i;
                }
                i=1;
                count=0;
            }
        }
        if(count>=sum)
        {
            next[j]=i;
        }
    }
}

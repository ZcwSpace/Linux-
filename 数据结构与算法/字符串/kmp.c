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
    getting_next(child_str,next);

    for(int i=1;i<=main_str[0];i++)
    {
        for(int j=1;j<=child_str[0];)
        {
            if(main_str[i]!=child_str[j])
            {
                if(j==child_str[0])
                {
                     printf("don't find\n");
                     exit(0);
                }
                j=next[j];
            }
            else 
            {
                if(j==child_str[0])
                {
                    printf("find\n");
                    exit(0);
                }
                i++;
                j++;
            }
        }
    }
}

//kmp算法的核心就是避免不必要的回溯。
//具体回溯多少由子串的元素决定。
//前一个元素决定后一个元素的回溯多少。
void getting_next(char child_str[],int next[])
{
    int count=1;

    next[1]=count;
    for(int i=1;i<child_str[0]-1;i++)
    {
        for(int j=i+1;j<child_str[0];j++)
        {
            if(child_str[i]==child_str[j])
            {
                next[j]=count;
                count++;
                i++;
            }
            else
            {
                next[j]=count;
                count=1;
            } 
        }
    }
    next[next[0]]=count;   
}

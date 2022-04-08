#include <stdio.h>
#include <string.h>  
#define LENGTH 10

void getting_next(char target[],int next[]);
void kmp(char string[],char target[]);

int main(void)
{
    char string[LENGTH],target[LENGTH];

    printf("请输入主串：");
    scanf("%s",string);
    printf("%d\n",strlen(string));
    
    printf("请输入目标串：");
    scanf("%s",target);

    return 0;
}
//实现kmp算法
void kmp(char string[],char target[])
{
    int next[LENGTH];

    getting_next(target,next);


}
void getting_next(char target[],int next[])
{
    int count=-1,temp=0;
    
    next[0]=-1;
    count++;
    for(int i=0;i<strlen(target)-1;i++)
    {
        temp=i;
        for(int j=i+1;j<strlen(target);j++)
        {
            if(target[i]==target[j])
            {
                next[j]=count;
                count++;
                i++;
            }
            else
            {
                count=0;
            } 
        }
        i=temp;
    }
}

#include <stdio.h>
#include <string.h>

int main(void)
{
    int flag = 0, i=0, j=0;
    char word[] = "deified";

    for(i=0, j=strlen(word)-1; i<j; i++, j--)
    {
        if(word[i] != word[j])
        {
            flag++; //记录不相等字符的个数
        }
    }

    if(flag == 0) 
    {
        printf("是回文\n");
    }
    else          
    {
        printf("不是回文\n");
    }

    return 0;
}
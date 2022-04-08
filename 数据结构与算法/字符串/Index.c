#include <stdio.h>
#include <string.h>

int Index(char master_str[],char child_str[],int addr);

int main(void)
{
    char  master_str[10],child_str[10];
    int addr;
    
    printf("请输入主串：");
    scanf("%s",master_str);
    printf("请输入字串：");
    scanf("%s",child_str);
    printf("请输入在主串中开始匹配的位置：");
    scanf("%d",&addr);

    int Index(master_str,child_straddr);

    return 0;
}
//T为非空字串。若主串第addr个字符之后存在与子串相等的子串，则返回第一个这样的子串在S中的位置，否则返回0。
int Index(char master_str[],char child_str[],int addr)
{
    if(strlen(child_str)==0)
    {
        printf("child_addr为空！");
        
        exit(0);
    }
    int n,m,i;
    char suv[10];

    if(addr>0)
    {
        n=strlen(master_str);
        m=strlen(child_str);
        i=addr;
        while(i<n-m+1)
        {
            
        }
    }
}
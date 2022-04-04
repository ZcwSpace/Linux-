#include <stdio.h>
#define LENGTH 10

void initing_next(char string[],int next[]);

int main(void)
{
    char string[LENGTH];
    char target[LENGTH];
    int next[LENGTH];

    printf("请输入主串：");
    scanf("%s",string);
    printf("请输入目标串：");
    scanf("%s",target);

    return 0;
}
void initing_next(char string[],int next[])
{

}
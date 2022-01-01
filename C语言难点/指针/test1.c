#include<stdio.h>

char *getWord(char);

int main()
{
    char input;

    printf("请输入一个字母：");
    scanf("%c",&input);

    printf("%s\n",getWord(input));

    return 0;
}
char *getWord(char c)
{
    switch(c)
    {
        //返回字符串时默认返回的时这个字符串的地址
        //字符串会放在常量存储区域，因此和函数没关系
        case 'A':return "Apple";
        case 'B':return "Banana";
        case 'C':return "Cat";
        case 'D':return "Dog";
        default:return "None";
    }
}
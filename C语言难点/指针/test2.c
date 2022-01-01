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
    char str1[]="Apple";
    char str2[]="Banana";
    char str3[]="Cat";
    char str4[]="Dog";
    char str5[]="None";

    switch(c)
    {
        //返回字符串时默认返回的时这个字符串的地址
        case 'A':return str1;
        case 'B':return str2;
        case 'C':return str3;
        case 'D':return str4;
        default:return str5;
        /*warning: function returns address of local variable [-Wreturn-local-addr]
         default:return str5;*/
    }
}
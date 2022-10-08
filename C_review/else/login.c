#include <stdio.h>
#include <string.h>

int login();
void mainMenu();

int main(void)
{
    if(!login())
    {
        printf("\n\n\t\t很遗憾，欢迎你下次再来！\n");

        return 1;
    }
    do
    {
        mainMenu();
    } while (1);
}
int login()
{
    char secretCode[7],ch;
    int i,number=3;

    printf("\n\n\n");
    printf("\t\t\t******欢迎使用学生成绩管理系统******\n");
    printf("\n\n");

    while(number>0)
    {
        i=0;
        printf("\n\t\t\t 请输入密码：");
        while((ch=getchar())!=13)
        {
            secretCode[i++]=ch;
            printf("*");
        }
        secretCode[i]='\0';
        if(strcmp(secretCode,"888888")==0)
        {
            break;
        }
        else
        {
            number--;
            if(number<=0)
            {
                break;
            }
            printf("\n\n\t\t 您还有%d次机会\n");
        }
    }
    if(number>0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void mainMenu()
{
    //system("clear");
    printf("\n\n\n\t\t\t******学生成绩管理系统******\n");
    getchar();
}
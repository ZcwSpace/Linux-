#include<stdio.h>
#include<stdlib.h>

extern char **environ;

int main(int argc,char** argv)
{
    int i;

    for(i=0;environ[i]!=NULL;i++)
    {
        //putenv("AA=wwwwwww");
        //putenv("AA=sssss");
        //setenv("BB","000",1);
        //unsetenv("BB");
        //char *buf=NULL;
        //buf=getenv("PATH");
        printf("%s\n",*environ);
    }
}
#include<stdio.h>

//extern char ** environ;

int main(int argc,char** argv,char **environ)
{
    int i=0;

    for(i;environ[i]!=NULL;i++)
    {
        printf("%s\n",environ[i]);
    }
}
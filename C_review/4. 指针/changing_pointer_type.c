#include <stdio.h>

int main(void)
{
    int num=1024;
    int *pi=&num;
    char *ps="FishC";
    void *pv;

/*
    pv=pi;
    printf("pi:%p,pv:%p\n",pi,pv);
    printf("*pv:%d\n",*(int *)pv);

    ps=(char*)pv;
    printf("ps:%s\n",ps);

    pv=ps;
    printf("ps:%p,pv:%p\n",ps,pv);
    printf("*pv:%s\n",(char *)pv);
*/
    pv=pi;
    printf("*pv:%d\n",*(int *)pv);
    //ps=(char *)pv;
    //ps=(char *)pi;
    //ps=(char *)(&num);
    printf("ps:%s\n",ps);

    return 0;
} 
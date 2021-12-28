#include<stdio.h>
#include<unistd.h>

int main(void)
{
    char buf[100]={0};
    char *p=getcwd(buf,99);

    printf("buf=%s\n",buf);
    printf("p=%p\n",p);//p:point：指针、地址
    printf("buf=%p\n",buf);

    return 0;
}
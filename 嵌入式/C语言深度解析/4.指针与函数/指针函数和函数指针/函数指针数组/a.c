#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

int div(int a, int b)
{
    return a / b;
}

int squ(int a)
{
    return a*a;
}

int main(void)
{
    int  i = 0, ret = 0;
    int da1= 0, da2 = 0;
    //函数参数不一致，所以不要指定任何形参
    int (*funp[5])() = {add, sub, mul, div, squ};

    while(1)
    {
        printf("0. add\n");
        printf("1. sub\n");
        printf("2. mul\n");
        printf("3. div\n");
        printf("4. square\n"); //平方
        printf("select\n");
        
        scanf("%d", &i);

        if(i == 4) 
        {
            printf("input data1\n");
            scanf("%d", &da1);
            
            ret = funp[i](da1);  //通过函数指针，调用对应函数
        }
        else 
        {
            printf("input data1, data2\n");
            scanf("%d %d", &da1, &da2);
            
            ret = funp[i](da1, da2); 
        }
        
        printf("ret = %d\n", ret);
}

    return 0;
}
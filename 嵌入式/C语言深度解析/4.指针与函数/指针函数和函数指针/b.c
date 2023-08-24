#include <stdio.h>
int fun(float a, int b)
{
    printf("a = %f\n", a);
    printf("b = %d\n", b);
    
    return 0;
}

int main(void)
{
    int (*funp)(float, int) = fun;
    
    funp(12.3, 100); //此时传递两个
    
    int (*funp1)(float) = (int (*)(float))fun; //fun的类型为int (*)(float, int) 
    
    funp1(12); //此时只传一个
    
    return 0;
}
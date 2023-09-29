#include <assert.h>
		
void fun(int a, int b)
{
    assert(a == 10);//断言a == 10，如果不成立，就报错
    assert(b == 20);
    
    //...
}

int main(void)
{	
    int a=5;
    int b=20;
    
    fun(a, b);
    
    return 0;
}			
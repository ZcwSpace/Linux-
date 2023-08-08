#include <stdio.h>
				
#define EXCHANGE(p1, p2) \
int tmp = 0;\
tmp = *p1;\
*p1 = *p2;\
*p2 = tmp;\

int main(void)
{       
    int a = 10; 
    int b = 30; 
                                    
    EXCHANGE(&a, &b); printf("a=%d, b=%d\n", a, b);
    

    return 0;
}		
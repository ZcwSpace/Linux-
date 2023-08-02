#include <stdio.h>

//#define DEBUG1
//#define DEBUG2
    
#ifdef DEBUG1
# define DBG1 printf("%s %d %s\n", __FILE__, __LINE__, __func__);  
#else
# define DBG1
#endif


#ifdef DEBUG2
# define DBG2(info1, info2) printf(info1, info2);                                               
#else
# define DBG2(info1, info2)
#endif
    
void exchange(int *p1, int *p2)
{      
    DBG1
    int tmp = 0;
    DBG1
    
    tmp = *p1;
    DBG1
    *p1 = *p2;
    DBG1
    *p2 = tmp;
    DBG1
}
                                                
int main(void)
{       
    int a = 10; 
    int b = 30; 
    
    DBG2("%s\n", "1111");
    
    DBG1							
    exchange(&a, &b);
    DBG1
    
    printf("a=%d, b=%d\n", a, b);

    DBG1

    return 0;
}
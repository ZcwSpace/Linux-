#include <stdio.h>

void fun(int m, char **p) 
{
    int i = 0;
    
    for(i=0; i<m; i++)
    {
        printf("%s\n", p[i]);
    }
}

int main(void)
{
    char *buf[] = {"how", "are", "you"};
    
    fun(3, buf);//buf等价于&buf[0], buf[0]的类型为char *，&buf[0]的类型就为char **
    
    return 0;
}
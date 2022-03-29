#include <stdio.h>

#define STR(s) # s 
#define TOGETHER(x,y) x##y
#define SHOWLIST(...) printf(#__VA_ARGS__) 
#define PRINT(format,...) printf(#format,##__VA_ARGS__)

int main(void)
{
    //printf("%s\n",STR(FISHC));
    //printf(STR(Hello  %s num = %d\n),STR(Fishc),520);
    //printf(STR(1 \n 2));
    //printf("1 \\n 2");
    //printf("%d\n",TOGETHER(5,20));
    //SHOWLIST(FISHC,520,3.14\n);
    //PRINT(num=%d\n,520);
    PRINT(Hello Fishc!\n);

    return 0;
}
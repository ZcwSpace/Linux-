#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    char str[30] = "20.30300";
    double ret = 0.0;

    ret = strtod(str, NULL); //第二个参数用不上，此时写NULL
    printf("%f\n", ret);
    */
    char str[30] = "20.30300 This is test";
    char *ptr = NULL; 		//放" This is test"第一个字符所在空间的指针
    double ret;

    ret = strtod(str, &ptr);
    printf("%f\n", ret);  //20.30300
    printf("%s", ptr);		 // This is test
    printf("%d\n", atoi("102"));
	printf("%ld\n", atol("102"));

    return 0;
}
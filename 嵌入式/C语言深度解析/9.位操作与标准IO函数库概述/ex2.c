#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buf[100] = {};
	char name[] = "zhangsan";
	float score = 60.5;
	int age 		= 25;

	sprintf(buf, "people inormation: %s %f %d", name, score, age);
    fprintf(stdout, "%s\n", buf); //打印验证

    return 0;
}
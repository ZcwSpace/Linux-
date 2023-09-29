#include <stdio.h>
#include <stdlib.h>

#define print_error(str) \
do{\
    fprintf(stderr, "File %s, Line %d, Function %s error\n", __FILE__, __LINE__, str);\
    perror("error Reason");\
    exit(-1);\
}while(0);

struct Student
{
    char name[30];
    float score;
    int age;
    int height;
}stu[3] = {{"zhangsan", 98.5, 25, 172}, {"lisi", 60.0, 22, 180}, {"王五", 70.5, 27, 175}}; //结构体数组

int main()
{
    FILE *fp = NULL;

    //fp = fopen("/home/zxf/Desktop/file.txt", "w"); 						//Linux
    fp = fopen("./test.txt", "w"); //whindows
    if(NULL == fp) print_error("fopen")
    
    /* 格式化输出 */
    int i = 0;
    for(i=0; i<3; i++)
    {	
        fprintf(fp, "%s %f %d %d\n", stu[i].name, stu[i].score, stu[i].age, stu[i].height);
    }	
    
    /* 整块写 */
    int ret = fwrite((void *)&stu, sizeof(stu), 1, fp);
    printf("ret = %d\n", ret);

    /* 分三块写（也就是分三个元素来写） */
    ret = fwrite((void *)&stu, sizeof(struct Student), 3, fp);
    printf("ret = %d\n", ret);

    return 0;
}
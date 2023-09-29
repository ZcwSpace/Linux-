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
}stu = {"zhangsan", 98.5, 25, 172}; //结构体数组

int main()
{
    FILE *fp = NULL;

    //fp = fopen("/home/zxf/Desktop/file.txt", "w+"); 						//Linux
    fp = fopen("./file.txt", "w+"); //whindows
    if(NULL == fp) print_error("fopen")

    /* 将结构体成员，格式化输出到文件中 */
    fprintf(fp, "%s %f %d %d", stu.name, stu.score, stu.age, stu.height);

    rewind(fp); //将读写的位置调回到文件头

    /* 从文件中读出字符串，格式转换后保存到“结构体变量”的各个成员中 */
    struct Student stu1 = {}; //保存读出的数据
    fscanf(fp, "%s%f%d%d", stu1.name, &stu1.score, &stu1.age, &stu1.height);
    
    //打印读出的数据
    printf("%s %f %d %d", stu1.name, stu1.score, stu1.age, stu1.height);

    fclose(fp);

    return 0;
}
#include <stdio.h>

struct Student 
{
    int num;
    char name;
    float score;
};
struct Student stu = {100, "zhangsan", "98.0"};

struct Teacher
{
    char name;
    int num;
};
struct Teacher tea;

tea = (struct Teacher)stu;

int main()
{
    int a;
    char b = '5';
    char c = 65;

    a = (int)b;

    printf("%d", a);
    

    return 0;
}
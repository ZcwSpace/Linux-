# 1 "e.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "e.c"
struct info_student
{
    char name[30];
    int num;
};
typedef struct info_student student;


struct info_teacher
{
    char name[30];
    int id;
};
typedef struct info_teacher teacher;


struct info_administor
{
    char name[30];
    int id;
};
typedef struct info_administor administor;
# 33 "e.c"
typedef struct info_major major; struct info_major
{
    char name[30];
    int id;
};
info(major);

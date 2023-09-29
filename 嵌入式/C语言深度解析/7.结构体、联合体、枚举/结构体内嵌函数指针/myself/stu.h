#ifndef STU
#define STU
typedef  struct student
{
    unsigned int id;
    char name[10];
    float score;
}Stu;

extern void initing_stu(int n, char *stu);
static void printing_tea(int n , char *stu);
static void altering_tea(int n , char * stu);
#endif

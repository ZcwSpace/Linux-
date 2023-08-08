#pragma once
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
/*1
#define info(parameter) struct info_##parameter{char name[30];\
    int id;\
};\
typedef struct info_##parameter parameter;
*/
/*2
#define info(parameter) typedef struct info_##parameter{char name[30];int id;}parameter;
*/
#define STRUCT(parameter) typedef struct info_##parameter parameter; struct info_##parameter 
STRUCT(major)
{
    char name[30];
    int id;
};
//info(major);
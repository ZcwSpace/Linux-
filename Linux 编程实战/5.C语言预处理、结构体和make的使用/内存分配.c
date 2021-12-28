#include<stdio.h>

struct person
{
  char name[20];
  int age;
  char sex;
  char phone[16];
};

int main()
{
  struct person p1;
  printf("%d\n",sizeof(p1));
}

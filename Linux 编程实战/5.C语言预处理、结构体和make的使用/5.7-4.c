#include<stdio.h>

typedef struct
{
  int number;
  char name[10];
  float Math;
  float English;
  float Computer;
}student,*pstudent;

int main()
{
  student person[10];
  int i,address;
  float altogether=0,max=0;

  for(i=0;i<10;i++)
    {
      printf("请输入第%d个学生的信息\n",i+1);
      printf("学号：");
      scanf("%d",&person[i].number);
      printf("姓名：");
      scanf("%s",&person[i].name);
      printf("高等数学成绩：");
      scanf("%f",&person[i].Math);
      printf("大学英语成绩：");
      scanf("%f",&person[i].English);
      printf("计算机程序设计语言成绩：");
      scanf("%f",&person[i].Computer);
    }
  for(i=0;i<10;i++)
    {
      if(person[i].Math>max)
	{
	  max=person[i].Math;
	  address=i;
	}
      altogether+=person[i].Math;
    }
  printf("高等数学的平均分为%f\n：",altogether/10);
  printf("最高分学生信息为：%d\t%s\t%f\t%f\t%f\n",person[address].number,person[address].name,person[address].Math,person[address].English,person[address].Computer);
  altogether=0,address=0;
  for(i=0;i<10;i++)
    {
      if(person[i].English>max)
	{
	  max=person[i].English;
	  address=i;
	}
      altogether+=person[i].English;
    }
  printf("大学英语的平均分为%f\n：",altogether/10);
  printf("最高分学生信息为：%d\t%s\t%f\t%f\t%f\n",person[address].number,person[address].name,person[address].Math,person[address].English,person[address].Computer);
  altogether=0,address=0;
  for(i=0;i<10;i++)
    {
      if(person[i].Computer>max)
	{
	  max=person[i].Computer;
	  address=i;
	}
      altogether+=person[i].Computer;
    }
  printf("计算机程序设计语言的平均分为%f\n：",altogether/10);
  printf("最高分学生信息为：%d\t%s\t%f\t%f\t%f\n",person[address].number,person[address].name,person[address].Math,person[address].English,person[address].Computer);
}

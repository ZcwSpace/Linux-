//两种标准的main声明方式
//int main(void)
//int main(int argc,char *argv[])//argc：所输入的参数的个数；argv：输入内容的地址
//int main(int argc,char **argv)//变形
#include<stdio.h>
/*
void main()//不标准，用在单片机编程
{
  printf("aancvalknckl");
}
*/
/*
int main()
{
  printf("akcklabnc");

  return 0;
}
*/
/*
int main(int argc,char **argv)
{
  printf("argc=%d\n",argc);
  for(int i=0;i<argc;i++)
    {
      printf("argv[%d]=%s\n",i,argv[i]);
    }

  return 0;
}
*/
int main(int number,char **string)
{
  printf("number=%d\n",number);
  for(int i=0;i<number;i++)
    {
      printf("string[%d]=%s\n",i,string[i]);
    }

  return 0;
}

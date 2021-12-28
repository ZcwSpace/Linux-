#include<stdio.h>

int main(int argc,int **argv)
{
  int mode=0740;
  int umask=045;

  printf("%o\n",mode& ~umask);

  return 0;
}

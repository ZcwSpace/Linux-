 #include<stdio.h>
 
 int main(void)

  {
      union c
      {
          int a;
          char b;
      }test;
      test.a = 1;
  
     if (test.b == 1) 
     {
         printf("%d",1);
     } 
     else 
     {
         printf("%d",0);
     }
     //输出1->小端序
     return 0;
}
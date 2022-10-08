#include <stdio.h>

int main()
{
    int array[4][5]={{0,0,0,0},{1,1,1,1},{2,2,2,2},{3,3,3,3}};

    printf("1.array目前表示的是什么？\n\n");

    printf("sizeof int:%d\n",sizeof(int));
    printf("array  :%p\n",array);
    printf("array+1:%p\n\n",array+1);
    
    printf("array指向二维数组中的第一个一维数组\n\n\n");
    
    printf("2.*(array+1)表示的是什么？\n\n");
    printf("*(array+1):%p\n",*(array+1));
    printf("array[1]:%p\n",array[1]);
    printf("sizeof *(array+1):%d\n",sizeof(*(array+1)));
    printf("sizeof array[1]:%d\n\n",sizeof(array[1]));

    printf("*(array+1)是array[1]，出现这种情况的原因是由于语法坛的出现\n\n\n");


    printf("*(*(array+1)+3)表示的是什么？\n\n");

    printf("*(*(array+1)+3):%d\n",*(*(array+1)+3));
    printf("array[1][3]:%d\n\n",array[1][3]);
    printf("*(*(array+1)+3)==array[1][3]\n\n\n");

    /*
    int **p1=array;
    printf("%d\n",*(*p1+1));
    报错
    */





}
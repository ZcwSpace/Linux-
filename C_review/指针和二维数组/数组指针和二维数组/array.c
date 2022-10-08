#include <stdio.h>

int main()
{
    //这俩种定义方法可以得到相同的效果
    //int array[2][3]={{0,1,2},{3,4,5}};
    int array[][3]={{0,1,2},{3,4,5}};

    //如何解释下列这个定义？
    int (*p)[3]=array;
    printf("%d\n",*(*p+1));

    

}
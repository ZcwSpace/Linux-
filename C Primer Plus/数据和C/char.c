#include <stdio.h>

int main(void)
{
    char T='c';
    char broiled;
    //如果你想把broiled的值变为字符‘T’
    broiled=T;//语义错误
    //broiled=“T”;//语法错误
    broiled=65;
    broiled='fate';
    broiled='\a';
    broiled='\v';
    broiled='\f';
    broiled='\040';
    broiled=040;
    broiled=07;
    printf("%c1",broiled);
    printf("\040",broiled);


    return 0;
}
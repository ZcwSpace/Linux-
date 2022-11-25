#include <stdio.h>

int jumping(int a[9],int addr);

int mian()
{
    int a[9]=0;

    for(int i=0;i<8;i++)
    {
        a[i]=i+1;
    }
    jumping(a,8);
}
int jumping(int a[9],int addr)
{
    int temp;
    if(addr==0)
    {
        temp=a[8];
        a[8]=a[addr];
        a[addr]=temp;
        jumping(a,8);

        temp=a[7];
        a[7]=a[addr];
        a[addr]=temp;
        jumping(a,7);
    }
    else{
        
    }
}
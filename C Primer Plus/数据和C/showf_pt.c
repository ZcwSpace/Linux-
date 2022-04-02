#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <fenv.h>

int main(void)
{
    /*
    float aboat=32000.0;
    double abet=2.14e9;
    long double dip=5.32e-5;
    printf("%f can be writen %e\n",aboat,aboat);//32000.000000 3.2e4
    //C99
    printf("And it's %a in hexadecimal,powers of 2 notation\n",aboat);
    printf("%f can be writen %e\n",abet,abet);
    printf("%Lf can be writen %Le\n",dip,dip);

    //overflow
    float toobig=3.4E38*100.0f;
    printf("%e\n",toobig);//inf
    */
    //NaN
    double result = asin(2) * 180.0 / 3.14;
    printf("result is :%f\n", result);
    if (errno == EDOM) {
        perror("errno == EDOM");
    }
    if (fetestexcept(FE_INVALID)) {
        printf("FE_INVALID is set\n");
    }

    return 0;
}
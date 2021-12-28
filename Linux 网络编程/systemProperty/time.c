#include<time.h>
#include<stdio.h>
#include<stdlib.h>
/*
struct tm {
               int tm_sec;    /* Seconds (0-60) 
               int tm_min;    /* Minutes (0-59) 
               int tm_hour;   /* Hours (0-23) 
               int tm_mday;   /* Day of the month (1-31) 
               int tm_mon;    /* Month (0-11) 
               int tm_year;   /* Year - 1900 
               int tm_wday;   /* Day of the week (0-6, Sunday = 0) 
               int tm_yday;   /* Day in the year (0-365, 1 Jan = 0) 
               int tm_isdst;  /* Daylight saving time 夏时令设置
           }
*/
int main(void)
{
    time_t tim;
    struct tm *tmp=NULL;
    char * strp=NULL;
    char buf[100]={0};

    //time(&time);
    tim=time(NULL);
    //strt=ctime(&tim);
    //tmp=gmtime(&tim);//国际时间
    tmp=localtime(&tim);//本地时间
    //tim=mktime(tmp);
    //strp=asctime(tmp);
    strftime(buf,sizeof(buf)-1,"%Y:%m:%d %H:%M:%S",tmp);

    
    //printf("tim=%d\n",tim);
    //printf("%s\n",strp);
    //printf("%d\n",tmp->tm_hour); 
    //printf("%d\n",tmp->tm_hour);
    printf("%s\n",buf);
    return 0;
}
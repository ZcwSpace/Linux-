#include<stdio.h>
#include<sys/types.h>
#include<grp.h>
/*
struct group {
               char   *gr_name;        /* group name 
               char   *gr_passwd;      /* group password 
               gid_t   gr_gid;         /* group ID 
               char  **gr_mem;         /* NULL-terminated array of pointers
                                          to names of group members 
           };
           */
int main(void)
{
    struct group *gr;
    int i;
    
    //gr=getgrgid(1000);
    gr=getgrnam("zcw");
    printf("%s:%s:%d:\n",gr->gr_name,gr->gr_passwd,gr->gr_gid);
    for(i=0;gr->gr_mem[i]!=NULL;i++)
    {
        printf("%s",gr->gr_mem[i]);
    }

    return 0;
}
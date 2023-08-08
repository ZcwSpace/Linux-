#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<pwd.h>

int main(void)
{
    /*
    struct passwd {
               char   *pw_name;        username 
               char   *pw_passwd;      user password 是否有密码
               uid_t   pw_uid;         user ID 
               gid_t   pw_gid;        /* group ID 
               char   *pw_gecos;      /* user information 
               char   *pw_dir;        /* home directory 
               char   *pw_shell;      /* shell program directory
           };
           */
    struct passwd * p=NULL;
    p=getpwuid(1001);
    //p=getpwnam("zcw");

    printf("%s %s %d %d %s %s %s\n",p->pw_name,p->pw_passwd,p->pw_uid,p->pw_gid,p->pw_gecos,p->pw_dir,p->pw_shell);

    return 0;
}
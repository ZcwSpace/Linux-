#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<dirent.h>
#include<errno.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>
/*
struct stat
        {
            dev_t st_dev;//块设备号(ID) dev_t=int
            ino_t st_ino;//inode节点号，文件属性所存inode节点的编号 ino_t=unsigned int
            mode_t st_mode;//文件类型和文件权限 ls 
            nlink_t st_nlink;//硬链接数         ls
            uid_t st_uid;//文件所属用户ID      ls
            gid_t st_gid;//文件所属组ID        ls
            dev_t st_rdev;//字符设备ID
            off_t st_size;//文件设备大小
            __blksize_t st_blksize;//系统每次按块Io操作是，块的大小（一般是512/1024）    
            blkcnt_t st_blocks;//块的索引号
            //Windows下，文件的时间，同样也分这三种
            time_t st_atime;//最后一次访问时间 read ls a:access访问 
            time_t st_matim;//最后一次修改时间 writem:modify修改
            time_t st_ctime;//最后一次属性修改时间，如权限被修改，文件所有者（属主）被修改
            //ls：表示这些属性使我们用ls查看时会显示的内容
    }
*/

void print_error(char *str);
void ls_fun(char * fileName);

int main(char argc,char** argv)
{
    int ret=0,i;
    struct stat sta={0};
    char fileType='0',buf[10]={0},tempBuf[]="rwxrwxrwx";
    
    if(argc!=2)
    {
        printf("error:The correct form is ./my_ls file.txt\n");
        exit(-1);
    }
    //获取文件属性
    //ret=stat(argv[1],&sta);
    ret=lstat(argv[1],&sta);
    if(ret==-1)
    {
        print_error("stat fail");
    }
    if(S_ISLNK(sta.st_mode)) fileType='l';
    else if( S_ISREG(sta.st_mode)) fileType='-';
    else if( S_ISDIR(sta.st_mode)) fileType='d';
    else if( S_ISCHR(sta.st_mode)) fileType='c';
    else if( S_ISBLK(sta.st_mode)) fileType='b';
    else if( S_ISFIFO(sta.st_mode)) fileType='p';
    else if(S_ISSOCK(sta.st_mode)) fileType='s';//sta.st_mode&__S_IFMT)==S_IFSOCK
    
    if(fileType!='d')
    {
        ls_fun(argv[1]);
    }
    else
    {
        char pwd[100]={0};
        getcwd(pwd,99);
        chdir(argv[1]);
        DIR *dirp =opendir(".");

        while(1)
        {
            struct dirent *direntp=readdir(dirp);
            if(direntp==NULL&&errno==0)
            {
                break;
            }
            ls_fun(direntp->d_name);
        }
        chdir(pwd);
    }

    return 0;
}
void print_error(char *str) 
{
    perror(str);
    exit(-1);
}

void ls_fun(char * fileName)
{
    int ret=0,i=0;
    struct stat sta={0};
    char fileType='0',buf[10]={0},tempBuf[]="rwxrwxrwx";
    struct passwd *p=NULL;
    struct group *gr;
    struct tm *tmp;
    char buf2[50]={0};

    ret=lstat(fileName,&sta);
    if(ret==-1)
    {
        print_error("stat fail");
    }

    if(S_ISLNK(sta.st_mode)) fileType='l';
    else if( S_ISREG(sta.st_mode)) fileType='-';
    else if( S_ISDIR(sta.st_mode)) fileType='d';
    else if( S_ISCHR(sta.st_mode)) fileType='c';
    else if( S_ISBLK(sta.st_mode)) fileType='b';
    else if( S_ISFIFO(sta.st_mode)) fileType='p';
    else if(S_ISSOCK(sta.st_mode)) fileType='s';

    for(i=0;i<9;i++)
    {
       if(sta.st_mode&(1<<(8-i)))
       {
           buf[i]=tempBuf[i];
       }
       else
       {
           buf[i]='-';
       }
    }
    //打印
    p=getpwuid(sta.st_uid);
    gr=getgrgid(sta.st_gid);
    tmp=localtime(&sta.st_atime);
    strftime(buf2,sizeof(buf2)-1,"%b %d %H %M:%S",tmp);
    printf("%c%s %d %s %s %ld %s %s",fileType,buf,sta.st_nlink,p->pw_name,gr->gr_name,sta.st_size,buf2,fileName);
    if(fileType=='l')
    {
        char sym_buf[30]={0};
        readlink(fileName,sym_buf,sizeof(sym_buf)-1);
        printf(" -> %s\n",sym_buf);
    }
    else
    {
        printf("\n");
    }

}
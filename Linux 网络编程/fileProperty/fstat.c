#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
/*
struct stat
        {
            dev_t st_dev;//块设备号(ID) dev_t=int
            ino_t st_ino;//inode节点号，文件属性所存inode节点的编号 ino_t=unsigned int
            mode_t st_mode;//文件类型和文件权限 ls 
            nlink_t st_nlink;//链接数         ls
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

int main(int argc,char** argv)
{
    int ret=0,i,fd;
    struct stat sta={0};
    char *fileType,buf[10]={0},tempBuf[]="rwxrwxrwx";
    fileType=(char *)malloc(sizeof(char *));
    
    if(argc!=2)
    {
        printf("error:The correct form is ./my_ls file.txt\n");
        exit(-1);
    }
    
    fd=open(argv[1],O_RDWR);
    if(fd==-1)
    {
        print_error("open fail");
        exit(-1);
    }
    fstat(fd,&sta);

    //获取文件属性
    if(S_ISLNK(sta.st_mode)) 
    {
        *fileType='l';
    }
    else if(S_ISREG(sta.st_mode)) 
    {
        *fileType='-';
    }
    else if(S_ISDIR(sta.st_mode)) 
    {
        *fileType='d';
    }
    else if(S_ISCHR(sta.st_mode)) 
    {
        *fileType='c';
    }
    else if(S_ISBLK(sta.st_mode)) 
    {
        *fileType='b';
    }
    else if(S_ISFIFO(sta.st_mode)) 
    {
        *fileType='p';
    }
    else if(S_ISSOCK(sta.st_mode)) 
    {
        *fileType='s';
    }
    
    //获取文件类型
    /*
    for(i=0;i<9;i++)
    {
        buf[i]='-';
    }
    if(sta.st_mode&S_IRUSR) buf[0]='r';
    else if(sta.st_mode&S_IWUSR) buf[1]='w';
    else if(sta.st_mode&S_IXUSR) buf[2]='x';
    else if(sta.st_mode&S_IRGRP) buf[3]='r';
    else if(sta.st_mode&S_IWGRP) buf[4]='W';
    else if(sta.st_mode&S_IXGRP) buf[5]='x';
    else if(sta.st_mode&S_IROTH) buf[6]='r';
    else if(sta.st_mode&S_IWOTH) buf[7]='w';
    else if(sta.st_mode&S_IXOTH) buf[8]='x';
    */
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
    printf("%c%s %d %lu %d %ld %ld %s\n",*fileType,buf,sta.st_nlink,sta.st_uid,sta.st_gid,sta.st_size,sta.st_atime,argv[1]);

    return 0;
}
void print_error(char *str) 
{
    perror(str);
    exit(-1);
}

//对于每一个尚未进行到字谜最后的有序四元组(行，列。方向，字符数等)我们可以测试所指的单词是否在单词表中                                                                                                                                                                                                                                                                                                           
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

void matching(int word_nums,char dic[][4], char word_mistery[4][4]);

int main(void)
{
    
    int word_nums;
    printf("请输入字典单词的个数:");
    scanf("%d",&word_nums);
    
    //初始化字典
    char dic[word_nums][4];
    for (int i = 0; i < word_nums; i++)
    {
        for (int j = 0; j <4; j++)
        {
            dic[i][j]='\0';
        }
    }

    //往字典内输入单词
    for (int i = 0; i < word_nums; i++)
    {
        printf("请输入字典内的第%d个单词:",i+1);
        scanf("%s",dic[i]);
    }

    //输入想要四阶字谜表的数据
    char word_mistery[4][4];
    for(int i=0;i<4;i++)
    {
        printf("请输入四阶字迷表的第%d行数据:",i+1);
        scanf("%s",word_mistery[i]);
    }

    printf("与单词表中匹配的单词有：\n");
    matching(word_nums,dic,word_mistery);

    return 0;
}

void matching(int word_nums,char dic[][4], char word_mistery[4][4])
{
    int temp_i,temp_j;
    
    for(int i=0;i<4;i++)
    {
        temp_i=i;
        for(int j=0;j<4;j++)
        {
            temp_j=j;

            //正下方向
            for(int k=0;k<word_nums;k++)
            {
                for(int m=0;m<4;m++,i++)
                {
                    if(word_mistery[i][j]!=dic[k][m]&&dic[k][m]!='\0')
                    {
                        break;
                    }
                    if(3==m||dic[k][m]=='\0')
                    {
                        printf("%s ",dic[k]);
                        break;
                    }
                }
                i=temp_i;
            }
            //正上方向
            for(int k=0;k<word_nums;k++)
            {
                for(int m=0;m<4;m++,i--)
                {
                    if(word_mistery[i][j]!=dic[k][m]&&dic[k][m]!='\0')
                    {
                        break;
                    }
                    if(3==m||dic[k][m]=='\0')
                    {
                        printf("%s ",dic[k]);
                        break;
                    }
                }
                i=temp_i;
            }
            //正右方向
            for(int k=0;k<word_nums;k++)
            { 
                for(int m=0;m<4;m++,j++)
                {
                    //匹配失败，跳出循环
                    if(word_mistery[i][j]!=dic[k][m]&&dic[k][m]!='\0')
                    {
                        break;
                    }

                    //匹配成功，输出数据并跳出循环
                    if(3==m||'\0'==dic[k][m])
                    {
                        printf("%s ",dic[k]);
                        break;
                    }
                }
                j=temp_j;
            }
            //正左方向
            for(int k=0;k<word_nums;k++)
            { 
                for(int m=0;m<4;m++,j--)
                {
                    //匹配失败，跳出循环
                    if(word_mistery[i][j]!=dic[k][m]&&dic[k][m]!='\0')
                    {
                        break;
                    }

                    //匹配成功，输出数据并跳出循环
                    if(3==m||'\0'==dic[k][m])
                    {
                        printf("%s ",dic[k]);
                        break;
                    }
                }
                j=temp_j;
            }
            //右斜下
            for(int k=0;k<word_nums;k++)
            {
                for(int m=0;m<4;m++,i++,j++)
                {
                    if(word_mistery[i][j]!=dic[k][m]&&dic[k][m]!='\0')
                    {
                            break;
                    }

                    if(3==m||dic[k][m]=='\0')
                    {
                        printf("%s ",dic[k]);
                        break;
                    }
                }
                i=temp_i;
                j=temp_j;
            }
           
            //右斜上方向
            for(int k=0;k<word_nums;k++)
            {
                for(int m=0;m<4;m++,i--,j++)
                {
                    if(word_mistery[i][j]!=dic[k][m]&&dic[k][m]!='\0')
                    {
                        break;
                    }

                    if(3==m||dic[k][m]=='\0')
                    {
                        printf("%s ",dic[k]);
                        break;
                    }
                }
                i=temp_i;
                j=temp_j;
            }

            //左斜下
            for(int k=0;k<word_nums;k++)
            {
                for(int m=0;m<4;m++,i++,j--)
                {
                    if(word_mistery[i][j]!=dic[k][m]&&dic[k][m]!='\0')
                    {
                        break;
                    }

                    if(3==m||dic[k][m]=='\0')
                    {
                        printf("%s ",dic[k]);
                        break;
                    }
                }
                i=temp_i;
                j=temp_j;
            }

            //左斜上
            for(int k=0;k<word_nums;k++)
            {
                for(int m=0;m<4;m++,i--,j--)
                {
                    if(word_mistery[i][j]!=dic[k][m]&&dic[k][m]!='\0')
                    {
                        break;
                    }

                    if(3==m||dic[k][m]=='\0')
                    {
                        printf("%s ",dic[k]);
                        break;
                    }
                }
                i=temp_i;
                j=temp_j;
            }  
        }
    }
    


    putchar('\n');
}
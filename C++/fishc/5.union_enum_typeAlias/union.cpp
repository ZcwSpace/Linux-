//union与结构相似，可以容纳多种不同类型的数据，但是它每次只能存储这些值中的某一个。
//定义一种变量来存放某种密码，我们可以选择生日，身份证后四位，宠物名。
union password
{
    unsigned long birthdy;
    unsigned short ssn;
    char * pet;    
};

password ps;
int main()
{
    ps.ssn=1001;
    ps.pet="Big white";//再次赋值会覆盖之前输入的1001

    return 0;
}

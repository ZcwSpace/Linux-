int fun(int n, int buf[][n]) 
//int fun(int buf[][n], int n)//报错,buf的作用域大于n的作用域
{
    //...
}
            
int main(void)
{
    int buf[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
        
    fun(4, buf);
    
}	
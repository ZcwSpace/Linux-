#define RESULT 1

void fun();

int main()
{
    fun();
    return RESULT;
}

#undef RESULT

void fun()
{
    printf(RESULT);//报错
}
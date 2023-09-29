#include "public.h"
#include "stu.h"
#include "tea.h"

Pub pub;

void initing(Pub temp)
{
    pub = temp;
}

void printing()
{
    pub.print(pub.arc, pub.arg);
}

void altering()
{
    pub.alter(pub.arc, pub.arg);
}
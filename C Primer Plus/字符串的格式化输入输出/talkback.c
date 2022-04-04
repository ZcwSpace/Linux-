#include <stdio.h>
#include <string.h>
#define DENSITY 62.4

int main (void)
{
    float weight,valume;
    int size,letters;
    char name[40]={0};

    printf("Hi! What's your first name?\n");
    scanf("%s",name);
    printf("%s,What's your weight in pounds?\n",name);
    scanf("%f",&weight);
    size=sizeof name;
    letters=strlen(name);
    valume=weight/DENSITY;
    printf("Well,%s,What's your valume is %2.2f cubic feet.\n",name,valume);
    printf("Also your first name has %d letters,\n",letters);
    printf("And we have %d betters to store it.\n",size);

    return 0;
}
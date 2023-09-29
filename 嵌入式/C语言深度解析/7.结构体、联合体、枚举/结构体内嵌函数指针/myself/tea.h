#ifndef TEA
#define TEA
typedef struct teacher
{
    unsigned int id;
    char name[10];
    float income;
}Tea;

extern void initing_tea(int n, char *tea);
static void printing_tea(int n , char *tea);
static void altering_tea(int n , char * tea);
#endif
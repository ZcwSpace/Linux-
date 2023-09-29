#ifndef PUB
#define PUB
typedef struct pub
{
    int arc;
    char * arg;
    void(*print)(int arc, char * arg);
    void(*alter)(int arc, char * arg);
}Pub; 

extern void initing(Pub pub);
extern void printing();
extern void altering();
#endif
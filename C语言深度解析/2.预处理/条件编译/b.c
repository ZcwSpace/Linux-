#include <stdio.h>

#define WINDOWS_XP

int main()
{
    #ifdef WINDOWS_XP
    printf("procedure word needed by windows_xp\n");
    #endif

    #ifndef LINUX
    printf("procedure word needed by Linux\n");
    #endif
}

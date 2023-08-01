#include <stdio.h>

#   define WINDOWS_XP

int main()
{
    #ifdef WINDOWS_XP  //#ifndef WINDOWS_XP
    printf("procedure word needed by Windows_xp\n");
    
    #else
    printf("procedure word needed by Linux\n");
    
    #endif
}
#include <stdio.h>

		int main(void)
		{
			int *p = NULL;
			
			printf("%d\n", sizeof(p)); //或者sizeof(int *))

			return 0;
		}
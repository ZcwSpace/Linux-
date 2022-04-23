#include <stdio.h>

void move(int n, char x, char y, char z);

#define APEC_P_NUM 1000//Asia-Pacific Economic Cooperation people numbers

int main()
{
    //int n;
    //int number;
    //int floor_num
    //int hanoi_tower_floor_num;
    //int ht_floor_num;//hanoi_tower_floor_number
    int num_of_floor;
	
	printf("ÇëÊäÈëººÅµËþµÄ²ãÊý£º");
	scanf_s("%d", &number);
	move(floor_number, 'X', 'Y', 'Z');
	
	return 0;
}
void move(int n, char x, char y, char z)
{
	if (n == 1)
	{
		printf("%c->%c\n", x, z);
	}
	else
	{
		move(n - 1, x, z, y);
		printf("%c->%c\n", x, z);
		move(n - 1, y, x, z);
	}
}

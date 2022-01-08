#include"헤더.h"
struct enemy
{
	int x, y, direction;
	struct Bullet;
};
typedef struct enemy ENEMY;
ENEMY Enemy_info[50];
int Enemy_Num;

void CreateEnemy(int count)
{
	static int Round;
	int i;
	if (count == 10)
	{
		Round = 1;
	}
	else if (count == 1000)
	{
		printf("1");
		Round = 2;
	}
	else if (count == 3000)
	{
		Round = 3;
	}
	else if (count = 6000)
	{
		Round = 4;
	}
	switch (Round)
	{
	case 1:
		Enemy_Num = 5;
		for (i = 0; i < Enemy_Num; i++)
		{
			Enemy_info[i].x = rand() % 120;
			Enemy_info[i].y = 2 + rand() % 4;
			gotoxy(Enemy_info[i].x, Enemy_info[i].y);
			Enemy_plane_1();
		}

	}
}

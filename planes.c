#include "헤더.h"
void myplane_1(int upgrade)
{
	if (upgrade == 0)
	{
		printf("ㅅ");
	}
	if (upgrade == 1)
	{
		printf("△");
	}
	if (upgrade == 2)
	{
		printf("▲");
	}
	if (upgrade >= 3)
	{
		printf("◈");
	}
}

void Enemy_plane_1(int HP)
{
	printf("▽");
}

void Enemy_plane_2(int HP)
{
	printf("▼");
}

void Enemy_plane_3(int HP)
{
	printf("♡");
}

void Enemy_plane_4(int HP)
{
	printf("♥");
}

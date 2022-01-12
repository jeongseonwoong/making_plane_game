#include"헤더.h"

struct bullet
{
	int x, y, direction;
};

typedef struct bullet BULLET;
BULLET Bullet_info[50];
int Bullet_Num;

struct enemy
{
	int x, y, HP;
	struct bullet Bullet_info[50];
};
typedef struct enemy ENEMY;
ENEMY Enemy_info[50];
static int Enemy_Num;

void MoveBullet(int *px, int *py, int dir )
{
	switch (dir)
	{
	case 1:
		*px = *px - 1;
		*py = *py + 1;
		break;
	case 2:
		*py = *py + 1;
		break;
	case 3:
		*px = *px + 1;
		*py = *py + 1;
		break;
	}
}

void Elem_Bullet(int Elem_Enemy_Num,int Elem_Bullet_Num,int *Bullet_Num)
{
	int i;
	for (i = Elem_Bullet_Num; i < *Bullet_Num; i++)
	{
		Enemy_info[Elem_Enemy_Num].Bullet_info[i].x = Enemy_info[Elem_Enemy_Num].Bullet_info[i+1].x;
		Enemy_info[Elem_Enemy_Num].Bullet_info[i].y = Enemy_info[Elem_Enemy_Num].Bullet_info[i + 1].y;
		Enemy_info[Elem_Enemy_Num].Bullet_info[i].direction = Enemy_info[Elem_Enemy_Num].Bullet_info[i + 1].direction;
	}
	Bullet_Num--;
}

void PrintBullet(int Enemy_Num,int Bullet_Num )
{
	int i,j;
	for (j = 0; j < Enemy_Num; j++)
	{
		for (i = 0; i < Bullet_Num; i++)
		{
			gotoxy(Enemy_info[j].Bullet_info[i].x, Enemy_info[j].Bullet_info[i].y);
			printf(" ");
			MoveBullet(&Enemy_info[j].Bullet_info[i].x, &Enemy_info[j].Bullet_info[i].y, Enemy_info[j].Bullet_info[i].direction);
			if (Enemy_info[j].Bullet_info[i].x < 0 || Enemy_info[j].Bullet_info[i].x>116)
			{
				Elem_Bullet(j,i,&Bullet_Num);
				i--;
			}
			else if (Bullet_info[i].y < 0 || Bullet_info[i].y>29)
			{
				Elem_Bullet(j,i,&Bullet_Num);
				i--;
			}
			gotoxy(Enemy_info[j].Bullet_info[i].x, Enemy_info[j].Bullet_info[i].y);
			printf("o");
		}
	}
}


void CreateEnemy(int count)
{
	int Round=0;
	int i,j;
	switch (count)
	{
	case 10:
		Round = 1;
		break;
	case 1000:
		Round = 2;
		break;
	case 3000:
		Round = 3;
		break;
	case 6000:
		Round = 4;
		break;
	}

	switch (Round)
	{
	case 1:
		Enemy_Num = 5;
		for (i = 0; i < Enemy_Num; i++)
		{
			Enemy_info[i].x = 20*i+18;
			Enemy_info[i].y = -1*(i-2)*(i-2) + 5;
			gotoxy(Enemy_info[i].x, Enemy_info[i].y);
			Enemy_plane_1();
		}
		Bullet_Num = 50;
		for (j = 0; j < Enemy_Num; j++)
		{
			for (i = 0; i < Bullet_Num; i++)
			{
				Enemy_info[j].Bullet_info[i].x = Enemy_info[j].x;
				Enemy_info[j].Bullet_info[i].y = Enemy_info[j].y+1;
				Enemy_info[j].Bullet_info[i].direction = 1 + rand() % 3;
			}
		}
		break;
	}
			PrintBullet(Enemy_Num,Bullet_Num);
}

#include"헤더.h"

struct Enemy_bullet
{
	int x, y, direction,pw;
};

typedef struct Enemy_bullet E_BULLET;
E_BULLET Bullet_info[50];
int E_Bullet_Num;

struct enemy
{
	int x, y, HP;
	struct Enemy_bullet Bullet_info[50];
};
typedef struct enemy ENEMY;
ENEMY Enemy_info[50];
static int Enemy_Num;

struct My_Bullet
{
	int x, y, direction, pw;
};
typedef struct My_Bullet M_BULLET;
M_BULLET Bullet_info_2[50];
int M_Bullet_Num;

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
	case 4:
		*px = *px - 1;
		*py = *py - 1;
		break;
	case 5:
		*py = *py - 1;
		break;
	case 6:
		*px = *px + 1;
		*py = *py - 1;
		break;
	}
}

void Elem_Bullet(int Elem_Enemy_Num,int Elem_Bullet_Num)
{
	gotoxy(Enemy_info[Elem_Enemy_Num].Bullet_info[Elem_Bullet_Num].x, Enemy_info[Elem_Enemy_Num].Bullet_info[Elem_Bullet_Num].y);
	printf(" ");
	Enemy_info[Elem_Enemy_Num].Bullet_info[Elem_Bullet_Num].x = Enemy_info[Elem_Enemy_Num].x;
	Enemy_info[Elem_Enemy_Num].Bullet_info[Elem_Bullet_Num].y = Enemy_info[Elem_Enemy_Num].y + 1;
}

void Elem_My_Bullet(int Elem_Bullet_Num,int New_x,int New_y)
{
	gotoxy(Bullet_info_2[Elem_Bullet_Num].x,Bullet_info_2[Elem_Bullet_Num].y);
	printf(" ");
	Bullet_info_2[Elem_Bullet_Num].x = NULL;
	Bullet_info_2[Elem_Bullet_Num].y = NULL;

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
				Elem_Bullet(j,i);
			}
			else if (Enemy_info[j].Bullet_info[i].y < 0 || Enemy_info[j].Bullet_info[i].y>=28)
			{
				Elem_Bullet(j, i);
			}
			gotoxy(Enemy_info[j].Bullet_info[i].x, Enemy_info[j].Bullet_info[i].y);
			printf("o");
		}
	}
}

void KillEnemy(int My_x ,int My_y ,int upgrade ,int count)
{
	static int i=0,x,ele=0;
	switch (upgrade)
	{
	case 0:
		M_Bullet_Num = 5;
		if (count % 20 == 0)
		{
			Bullet_info_2[i].pw = 1;
			Bullet_info_2[i].direction = 5;
			Bullet_info_2[i].x = My_x;
			Bullet_info_2[i].y = My_y - 1;
			i++;
		}
		for (x = 0; x < i; x++)
		{
			if (Bullet_info_2[x].x != NULL || Bullet_info_2[x].y != NULL)
			{
				gotoxy(Bullet_info_2[x].x, Bullet_info_2[x].y);
				printf(" ");
				MoveBullet(&Bullet_info_2[x].x, &Bullet_info_2[x].y, Bullet_info_2[x].direction);
				if (Bullet_info_2[x].x < 0 || Bullet_info_2[x].x>116)
				{
					Elem_My_Bullet(x, My_x, My_y);
				}
				else if (Bullet_info_2[x].y < 0 || Bullet_info_2[x].y >= 28)
				{
					Elem_My_Bullet(x, My_x, My_y);
				}
				gotoxy(Bullet_info_2[x].x, Bullet_info_2[x].y);
				printf("o");
			}
		}
		break;
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
			Enemy_info[i].HP = 3;
			gotoxy(Enemy_info[i].x, Enemy_info[i].y);
			Enemy_plane_1();
		}
		E_Bullet_Num = 4;
		for (j = 0; j < Enemy_Num; j++)
		{
			for (i = 0; i < E_Bullet_Num; i++)
			{
				Enemy_info[j].Bullet_info[i].x = Enemy_info[j].x;
				Enemy_info[j].Bullet_info[i].y = Enemy_info[j].y+1;
				Enemy_info[j].Bullet_info[i].direction = 1 + rand() % 3;
			}
		}
		break;
	}
			PrintBullet(Enemy_Num,E_Bullet_Num);
}

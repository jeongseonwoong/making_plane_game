#include"헤더.h"

struct Enemy_bullet
{
	int x, y, direction, pw;
};

typedef struct Enemy_bullet E_BULLET;
E_BULLET Bullet_info[50];
int E_Bullet_Num;

struct enemy
{
	int x, y, HP, upgrade;
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

void MoveBullet(int* px, int* py, int dir)
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

void Elem_Bullet(int Elem_Enemy_Num, int Elem_Bullet_Num)
{
	Enemy_info[Elem_Enemy_Num].Bullet_info[Elem_Bullet_Num].x = Enemy_info[Elem_Enemy_Num].x;
	Enemy_info[Elem_Enemy_Num].Bullet_info[Elem_Bullet_Num].y = Enemy_info[Elem_Enemy_Num].y + 1;
}

void Elem_My_Bullet(int Elem_Bullet_Num)
{
	Bullet_info_2[Elem_Bullet_Num].x = NULL;
	Bullet_info_2[Elem_Bullet_Num].y = NULL;
}

int MyHp(int My_x,int My_y,int upgrade, int *My_Plane_HP)
{
	int i, j;
	for (j = 0; j < Enemy_Num; j++)
	{
		for (i = 0; i < E_Bullet_Num; i++)
		{
			if (Enemy_info[j].Bullet_info[i].x == My_x || Enemy_info[j].Bullet_info[i].x == My_x + 1)
			{
				if (Enemy_info[j].Bullet_info[i].y == My_y)
				{
					*My_Plane_HP = *My_Plane_HP - Enemy_info[j].Bullet_info[i].pw;
				}
			}
		}
	}
	if (*My_Plane_HP == 0)
	{
		return 0;
	}
	else return 1;
}

void PrintBullet(int Enemy_Num, int Bullet_Num,int My_x,int My_y)
{
	int i, j;
	for (j = 0; j < Enemy_Num; j++)
	{
		for (i = 0; i < Bullet_Num; i++)
		{
			if (Enemy_info[j].Bullet_info[i].x != NULL && Enemy_info[j].Bullet_info[i].y != NULL)
			{
				gotoxy(Enemy_info[j].Bullet_info[i].x, Enemy_info[j].Bullet_info[i].y);
				printf("  ");
				MoveBullet(&Enemy_info[j].Bullet_info[i].x, &Enemy_info[j].Bullet_info[i].y, Enemy_info[j].Bullet_info[i].direction);
				if (Enemy_info[j].Bullet_info[i].x < 0 || Enemy_info[j].Bullet_info[i].x>116)
				{
					if (Enemy_info[j].x == NULL && Enemy_info[j].y == NULL)
					{
						Enemy_info[j].Bullet_info[i].x = NULL;
						Enemy_info[j].Bullet_info[i].y = NULL;
						continue;
					}
					else
					{
						Elem_Bullet(j, i);
					}
				}
				else if (Enemy_info[j].Bullet_info[i].y < 0 || Enemy_info[j].Bullet_info[i].y > 28)
				{
					if (Enemy_info[j].x == NULL && Enemy_info[j].y == NULL)
					{
						Enemy_info[j].Bullet_info[i].x = NULL;
						Enemy_info[j].Bullet_info[i].y = NULL;
						continue;
					}
					else
					{
						Elem_Bullet(j, i);
					}
				}
				gotoxy(Enemy_info[j].Bullet_info[i].x, Enemy_info[j].Bullet_info[i].y);
				printf("o");
			}
		}
	}
}

void PrintMyBullet(int My_x, int My_y, int i)
{
	int en_y, x;
	for (x = 0; x < i; x++)
	{
		if (Bullet_info_2[x].x != NULL || Bullet_info_2[x].y != NULL)
		{
			gotoxy(Bullet_info_2[x].x, Bullet_info_2[x].y);
			printf(" ");
			MoveBullet(&Bullet_info_2[x].x, &Bullet_info_2[x].y, Bullet_info_2[x].direction);
			if (Bullet_info_2[x].x < 0 || Bullet_info_2[x].x>116)
			{
				Elem_My_Bullet(x);
			}
			else if (Bullet_info_2[x].y < 0 || Bullet_info_2[x].y >= 28)
			{
				Elem_My_Bullet(x);
			}
			gotoxy(Bullet_info_2[x].x, Bullet_info_2[x].y);
			printf("o");

			for (en_y = 0; en_y < Enemy_Num; en_y++)
			{
				if (Bullet_info_2[x].x == Enemy_info[en_y].x || Bullet_info_2[x].x == Enemy_info[en_y].x + 1)
				{
					if (Bullet_info_2[x].y == Enemy_info[en_y].y)
					{
						Enemy_info[en_y].HP = Enemy_info[en_y].HP - Bullet_info_2[x].pw;
						Elem_My_Bullet(x);
					}
				}
				if (Enemy_info[en_y].HP <= 0)
				{
					gotoxy(Enemy_info[en_y].x, Enemy_info[en_y].y);
					printf("       ");
					Enemy_info[en_y].x = NULL;
					Enemy_info[en_y].y = NULL;
				}
			}
		}
	}
}


void MyBullet(int My_x, int My_y, int upgrade, int count)
{
	static int i_1 = 0, i_2 = 0, i_3 = 0, i_4 = 0;
	switch (upgrade)
	{
	case 0:
		M_Bullet_Num = 5;
		if (count % 18 == 0)
		{
			Bullet_info_2[i_1].pw = 1;
			Bullet_info_2[i_1].direction = 5;
			Bullet_info_2[i_1].x = My_x;
			Bullet_info_2[i_1].y = My_y - 1;
			i_1++;
		}
		PrintMyBullet(My_x, My_y, i_1);
		break;
	case 1:
		M_Bullet_Num = 10;
		if (count % 15 == 0)
		{
			Bullet_info_2[i_2].pw = 2;
			Bullet_info_2[i_2].direction = 5;
			Bullet_info_2[i_2].x = My_x;
			Bullet_info_2[i_2].y = My_y - 1;
			i_2++;
		}
		PrintMyBullet(My_x, My_y, i_2);
		break;
	case 2:
		M_Bullet_Num = 10;
		if (count % 10 == 0)
		{
			Bullet_info_2[i_3].pw = 3;
			Bullet_info_2[i_3].direction = 5;
			Bullet_info_2[i_3].x = My_x;
			Bullet_info_2[i_3].y = My_y - 1;
			i_3++;
		}
		PrintMyBullet(My_x, My_y, i_3);
		break;
	}

}

void PrintEnemy()
{
	int i;
	for (i = 0; i < Enemy_Num; i++)
	{
		if (Enemy_info[i].x != NULL && Enemy_info[i].y != NULL)
		{
			gotoxy(Enemy_info[i].x, Enemy_info[i].y);
			switch (Enemy_info[i].upgrade)
			{
			case 1:
				printf("▽ HP:%d", Enemy_info[i].HP);
				break;
			case 2:
				printf("▼ HP:%d", Enemy_info[i].HP);
				break;
			case 3:
				printf("♡ HP:%d", Enemy_info[i].HP);
				break;
			case 4:
				printf("♥ HP:%d", Enemy_info[i].HP);
				break;
			}
		}
	}
}


void CreateEnemy(int My_x,int My_y, int count)
{
	int Round_Start = 0, i, j;

	if (count == 10)
	{
		Round_Start = 1;
	}
	else if (count==800)
	{

		Round_Start = 2;
	}
	else if (count == 2000)
	{
		Round_Start = 3;
	}
	else if (count == 4000)
	{
		Round_Start = 4;
	}

	if (Round_Start == 1)
	{
		Enemy_Num = 5;
		for (i = 0; i < Enemy_Num; i++)
		{
			Enemy_info[i].x = 20 * i + 18;
			Enemy_info[i].y = -1 * (i - 2) * (i - 2) + 5;
			Enemy_info[i].HP = 3;
			Enemy_info[i].upgrade = 1;
		}
		E_Bullet_Num = 3;
		for (j = 0; j < Enemy_Num; j++)
		{
			for (i = 0; i < E_Bullet_Num; i++)
			{
				Enemy_info[j].Bullet_info[i].x = Enemy_info[j].x;
				Enemy_info[j].Bullet_info[i].y = Enemy_info[j].y + 1;
				Enemy_info[j].Bullet_info[i].direction = 3-i;
				Enemy_info[j].Bullet_info[i].pw = 1;
			}
		}
	}
	else if (Round_Start == 2)
	{
		system("cls");
		Enemy_Num = 7;
		for (i = 0; i < 5; i++)
		{
			Enemy_info[i].x = 20 * i + 18;
			Enemy_info[i].y = -1 * (i - 2) * (i - 2) + 5;
			Enemy_info[i].HP = 3;
			Enemy_info[i].upgrade = 1;
		}
		for (i = 5; i < 7; i++)
		{
			Enemy_info[i].x = 61 * i - 277;
			Enemy_info[i].y = 2;
			Enemy_info[i].HP = 7;
			Enemy_info[i].upgrade = 2;
		}
		E_Bullet_Num = 3;
		for (j = 0; j < Enemy_Num; j++)
		{
			for (i = 0; i < E_Bullet_Num; i++)
			{
				Enemy_info[j].Bullet_info[i].x = Enemy_info[j].x;
				Enemy_info[j].Bullet_info[i].y = Enemy_info[j].y + 1;
				Enemy_info[j].Bullet_info[i].direction = 3-i;
				if (Enemy_info[j].upgrade == 1)
				{
					Enemy_info[j].Bullet_info[i].pw = 1;
				}
				else if (Enemy_info[j].upgrade == 2)
				{
					Enemy_info[j].Bullet_info[i].pw = 2;
				}
			}
		}
	}
	PrintEnemy();
	PrintBullet(Enemy_Num, E_Bullet_Num, My_x, My_y);

}

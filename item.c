#include "헤더.h"
struct item
{
	int x=0, y=0, duration = 0;
};

typedef struct item ITEM;
ITEM Item_info[50];
int Item_Num = 0;

void item(int count, int x, int y, int* upgrade, int *My_Plane_HP)
{

	int starting_time, starting_time2, starting_time3, i,j;
	starting_time = count % 300;
	starting_time2 = count % 800;
	starting_time3 = count % 1500;


	if (starting_time == 0)
	{
		Item_info[Item_Num].x = rand() % 116;
		Item_info[Item_Num].y = 4 + rand() % 25;
		gotoxy(Item_info[Item_Num].x, Item_info[Item_Num].y);
		printf("☆");
		Item_Num++;
	}
	else if(starting_time2==0)
	{
		Item_info[Item_Num].x = rand() % 116;
		Item_info[Item_Num].y = 4 + rand() % 25;
		gotoxy(Item_info[Item_Num].x, Item_info[Item_Num].y);
		printf("◇");
		Item_Num++;
	}
	for (i = 0; i < Item_Num; i++)
	{
		if (Item_info[i].y == y)
		{
			if (Item_info[i].x == x||Item_info[i].x==x+1)
			{
				*upgrade = *upgrade + 1;
				switch (*upgrade)
				{
				case 0:
					*My_Plane_HP = 5;
					break;
				case 1:
					*My_Plane_HP = 10;
					break;
				case 2:
					*My_Plane_HP = 15;
					break;
				case 3:
					*My_Plane_HP = 20;
					break;
				}
				gotoxy(Item_info[i].x, Item_info[i].y);
				printf("  ");
				for (j = Item_Num; j > i; j--)
				{
					Item_info[j - 1].x = Item_info[j].x;
					Item_info[j - 1].y = Item_info[j].y;
				}
				Item_Num--;
			}
		}
		Item_info[i].duration++;
		if (Item_info[i].duration % 150==0)
		{
			gotoxy(Item_info[i].x, Item_info[i].y);
			printf("  ");
			for (j = Item_Num; j > i; j--)
			{
				Item_info[j - 1].x = Item_info[j].x;
				Item_info[j - 1].y = Item_info[j].y;
			}
			Item_Num--;
		}
	}

}

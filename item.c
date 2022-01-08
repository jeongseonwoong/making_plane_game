#include "헤더.h"
struct item
{
	int x, y, duration = 0;
};

typedef struct item ITEM;
ITEM Item_info[50];
int Item_Num = 0;

void item(int count, int x, int y, int* upgrade)
{

	int starting_time, i;
	starting_time = count % 300;


	if (starting_time == 0)
	{
		Item_info[Item_Num].x = rand() % 116;
		Item_info[Item_Num].y = 4 + rand() % 25;
		gotoxy(Item_info[Item_Num].x, Item_info[Item_Num].y);
		printf("☆");
		Item_Num++;
	}
	for (i = 0; i < Item_Num; i++)
	{
		if (Item_info[i].y == y)
		{
			if (Item_info[i].x == x||Item_info[i].x==x+1)
			{
				*upgrade = *upgrade + 1;
				gotoxy(Item_info[i].x, Item_info[i].y);
				printf("  ");
				Item_info[i].x = NULL;
				Item_info[i].y = NULL;
			}
		}
		Item_info[i].duration++;
		if (Item_info[i].duration == 150)
		{
			gotoxy(Item_info[i].x, Item_info[i].y);
			printf("  ");
			Item_info[i].x = NULL;
			Item_info[i].y = NULL;
		}
	}
}

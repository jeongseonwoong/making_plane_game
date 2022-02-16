#include "헤더.h"

int StartPoint()
{
	int key=1,x,y;
	gotoxy(50, 4);//116.29
	printf("총알 피하기 게임\n\n");
	gotoxy(52, 15);
	x = 50, y = 15;
	printf("게임 시작");
	gotoxy(52, 16);
	printf("게임 종료");
	gotoxy(52, 17);
	printf("환경설정");
	gotoxy(x, y);
	printf("▶");
	while (key != 13)
	{
		key = _getch();
		gotoxy(x, y);
		printf("  ");
		if (key == 72&&y>15)
		{
			y--;
		}
		else if (key == 80&&y<17)
		{
			y++;
		}
		if (y <= 17 && y >= 15)
		{
			gotoxy(x, y);
			printf("▶");
		}
	}
	if (y == 15)
	{
		system("cls");
		return 1;
	}
	else if (y == 16)
	{
		system("cls");
		return 0;
	}
	else if (y == 17)
	{
		system("cls");
		return 2;
	}
	return 1;
}

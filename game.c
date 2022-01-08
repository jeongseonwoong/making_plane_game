#include "헤더.h"


void gotoxy(int x, int y)
{
	COORD CursorPosition = { x, y }; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

void rates(int &count,int &refreshRate)
{
	gotoxy(0, 0);
	printf("RATE: %d", count);
	if (count % refreshRate == 0)printf("\n%d", count / refreshRate);
	Sleep(1000 / refreshRate);
	count++;
}

void movement(int &x,int&y,int upgrade,int count)
{
	gotoxy(x, y);
	printf("  ");
	if (GetAsyncKeyState(VK_LEFT) && x > 0)
	{
		x--;
	}
	if (GetAsyncKeyState(VK_RIGHT) && x < 116)
	{
		x++;
	}
	if (GetAsyncKeyState(VK_UP) && y > 0)
	{
		y--;
	}
	if (GetAsyncKeyState(VK_DOWN) && y < 29)
	{
		y++;
	}
	gotoxy(x, y);
	myplane_1(upgrade);
}


int game()
{
	int refreshRate = 50;
	int x = 58, y = 13;
	int count = 1,upgrade=0;
	while (TRUE)
	{
		movement(x,y,upgrade,count);
		item(count,x,y,&upgrade);
		CreateEnemy(count);
		rates(count,refreshRate);
	}
}

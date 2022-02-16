#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
int main();
void game();
int StartPoint();
void CreateEnemy(int,int,int);
int MyHp(int,int,int,int*);
void myplane_1(int);
void gotoxy(int,int);
void item(int,int,int,int*,int*);
void MyBullet(int,int,int,int);

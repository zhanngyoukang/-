# 打飞机小游戏介绍
## **变量定义**
---
```C++
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#define MAX 100
long long int speed = 0;//控制敌机的速度 
int position_x, position_y;//飞机的所在位置 
int high, width;//地图的大小 
int bullet_x, bullet_y;//子弹的位置 
int enemy_x, enemy_y;//敌人的位置 
int map[MAX][MAX];
/*0表示空白，1表示战机*的区域，2表示敌人战机的位置。
3表示上下围墙，4表示左右围墙,5表示子弹的位置*/
int score;//分数
```
## **函数定义**
---
### 初始化所有信息
```C++
void starup()
{
	high = 20;
	width = 30;
	position_x = high / 2;
	position_y = width / 2;
	bullet_x = 0;
	bullet_y = position_y;
	enemy_x = 2;
	enemy_y = position_y - 1;
	score = 0;

}
```
### 初始化地图
```C++
void startMap()
{       //左右围墙的初始化以及空白区域的初始化
	int i, j;
	for (i = 1; i <= high - 1; i++)
	{
		map[i][1] = 4;
		for (j = 2; j <= width - 1; j++)
			map[i][j] = 0;
		map[i][width] = 4;
	}
	//下方围墙的初始化 
	i = high;
	for (j = 1; j <= width; j++)
		map[i][j] = 3;

	map[bullet_x][bullet_y] = 5;
	/*初始化战机大小*/
	map[position_x - 1][position_y] = 1;
	i = position_x;
	for (j = position_y - 2; j <= position_y + 2; j++)
		map[i][j] = 1;
	map[position_x + 1][position_y - 1] = 1;
	map[position_x + 1][position_y + 1] = 1;
	/***      初始化结束         **/

	/* 初始化敌机大小 */
	map[enemy_x][enemy_y] = 2;
	map[enemy_x - 1][enemy_y - 1] = 2;
	map[enemy_x - 1][enemy_y + 1] = 2;
	/***      初始化结束         **/
} 
```
### 隐藏光标
```C++
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
```
### 清理多余的屏幕
```C++
void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}
```
### 与输入无关的更新
```C++
void updateWithoutInput() 
{
	if (bullet_x > 0)
		bullet_x--;   //实现子弹的移动
	if ((bullet_x == enemy_x) && (bullet_y == enemy_y))//当敌机被击中时 
	{
		score++;
		enemy_x = 0;
		enemy_y = rand() % width;
		bullet_x = 0;
	}
	if (enemy_x > high)//当敌机超出区域 
	{
		enemy_x = 0;
		enemy_y = rand() % width;
	}
	if (speed == 1)
		for (int i = 1; i <= 10000; i++)//用来控制敌机的速度 
		{
			for (int j = 1; j <= 10000; j++)
			{
				speed = 1;
			}
		}
	speed = 0;
	if (speed == 0)
	{
		enemy_x++;
		speed = 1;
	}
}
```
### 与输入有关的更新
```C++
void updateWithInput()
{
	char input;
	if (_kbhit())  //判断有无输入
	{
		input = _getch();   //不需要回车的连续输入
		if (input == 'a')
			position_y--;
		if (input == 's')
			position_x++;
		if (input == 'd')
			position_y++;
		if (input == 'w')
			position_x--;
		if (input == ' ')
		{
			bullet_x = position_x - 1;
			bullet_y = position_y;
		}
	}
}
```
### 界面显示及操作说明
```C++
void show()
{
	gotoxy(0, 0);
	int i, j;
	for (i = 1; i <= high; i++)
	{
		for (j = 1; j <= width; j++)
		{
			if (map[i][j] == 0)
				printf(" ");
			if (map[i][j] == 1)
				printf("*");
			if (map[i][j] == 2)
				printf("#");
			if (map[i][j] == 3)
				printf("~");
			if (map[i][j] == 4)
				printf("|");
			if (map[i][j] == 5)
				printf("|");
		}
		printf("\n");
	}
	printf("\n你的得分:%d\n\n", score);
	printf("操作说明: ASDW分别操作 左下右上四个的移动\n");
	printf("**空格是发出子弹**\n");
}
```
## **主函数运行**
---
```C++
int main()
{
	starup();
	while (1)
	{
		HideCursor();
		startMap();
		show();
		updateWithoutInput();
		updateWithInput();
	}
	return 0;
}
```
## **游戏界面显示**
---
![游戏界面](jietu.png '游戏界面')

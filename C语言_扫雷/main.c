#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void game()
{
	//雷的信息存储
	//1.布置雷的信息
	char mine[ROWS][COLS] = { 0 };
	//2.排查雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印9x9棋盘
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
	FindMine(mine, show, ROW, COL);
}
void test()
{	
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		meun();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新选择:>\a\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}
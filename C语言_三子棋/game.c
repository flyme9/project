#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{	//菜单栏
	printf("********************************\n");
	printf("****         三子棋         ****\n");
	printf("****    1.play    0.exit    ****\n");
	printf("********************************\n");
}
void InitBoard(char board[ROW][COL], int row, int col)
{	//初始化棋盘
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col)
{	//输出棋盘格子
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			//1. 打印一行的数据
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//2. 打印分割行
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j<col - 1)
					printf("|");
			}
			printf("\n");
		}

	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{	//玩家
	int x = 0;
	int y = 0;
	printf("玩家走：>\n");
	while (1)
	{
		printf("请输入要下的坐标:>\n");
		scanf("%d%d", &x, &y);
		//判断x,y坐标的合法性
		if (x >= 1 && x <= row  && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标被占用\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入!\a\n");
		}
	}
}
void ComputerMove(char board[ROW][COL], int row,int col)
{	//电脑
	int x = 0;
	int y = 0;
	printf("电脑走:>\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
int IsFull(char board[ROW][COL], int row, int col)
{	//判断棋盘是否满棋
	int x = 0;
	int y = 0;
	for (x = 0; x < row; x++)
	{
		for (y = 0; y < col; y++)
		{
			if (board[x][y] == ' ')
			{
				return 0;//没满
			}
		}
	}
	return 1;//满了
}
char IsWin(char board[ROW][COL],int row,int col)
{	//判断对局情况
	int i = 0;
	for (i = 0; i < row; i++)
	{	//判断横排的结果
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	for (i = 0; i < col; i++)
	{	//判断竖排的结果
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//判断斜线结果
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][1] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';//平局
	}
	return 'C';//继续
}
void game()
{
	//创建数组
	char board[ROW][COL] = { 0 };
	char ret = 0;
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//棋盘显示
	DisplayBoard(board, ROW, COL);
	while (1)
	{

		PlayerMove(board, ROW, COL);//玩家
		DisplayBoard(board, ROW, COL);//打印输入后棋盘
		ret = IsWin(board, ROW, COL);//判断结果
		if (ret != 'C')//
		{
			break;
		}
		ComputerMove(board, ROW, COL); //电脑
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}
#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{	//�˵���
	printf("********************************\n");
	printf("****         ������         ****\n");
	printf("****    1.play    0.exit    ****\n");
	printf("********************************\n");
}
void InitBoard(char board[ROW][COL], int row, int col)
{	//��ʼ������
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
{	//������̸���
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			//1. ��ӡһ�е�����
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//2. ��ӡ�ָ���
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
{	//���
	int x = 0;
	int y = 0;
	printf("����ߣ�>\n");
	while (1)
	{
		printf("������Ҫ�µ�����:>\n");
		scanf("%d%d", &x, &y);
		//�ж�x,y����ĺϷ���
		if (x >= 1 && x <= row  && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�����걻ռ��\n");
			}
		}
		else
		{
			printf("����Ƿ�������������!\a\n");
		}
	}
}
void ComputerMove(char board[ROW][COL], int row,int col)
{	//����
	int x = 0;
	int y = 0;
	printf("������:>\n");
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
{	//�ж������Ƿ�����
	int x = 0;
	int y = 0;
	for (x = 0; x < row; x++)
	{
		for (y = 0; y < col; y++)
		{
			if (board[x][y] == ' ')
			{
				return 0;//û��
			}
		}
	}
	return 1;//����
}
char IsWin(char board[ROW][COL],int row,int col)
{	//�ж϶Ծ����
	int i = 0;
	for (i = 0; i < row; i++)
	{	//�жϺ��ŵĽ��
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	for (i = 0; i < col; i++)
	{	//�ж����ŵĽ��
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//�ж�б�߽��
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
		return 'Q';//ƽ��
	}
	return 'C';//����
}
void game()
{
	//��������
	char board[ROW][COL] = { 0 };
	char ret = 0;
	//��ʼ������
	InitBoard(board, ROW, COL);
	//������ʾ
	DisplayBoard(board, ROW, COL);
	while (1)
	{

		PlayerMove(board, ROW, COL);//���
		DisplayBoard(board, ROW, COL);//��ӡ���������
		ret = IsWin(board, ROW, COL);//�жϽ��
		if (ret != 'C')//
		{
			break;
		}
		ComputerMove(board, ROW, COL); //����
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}
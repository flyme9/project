#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void game()
{
	//�׵���Ϣ�洢
	//1.�����׵���Ϣ
	char mine[ROWS][COLS] = { 0 };
	//2.�Ų��׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//��ӡ9x9����
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//������
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
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������������ѡ��:>\a\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}
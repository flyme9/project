#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void test()
{
	int intput = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &intput);
		switch (intput)
		{
		case 1:
			printf("������\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (intput);
}
int main()
{
	test();
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void test()
{
	int intput = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &intput);
		switch (intput)
		{
		case 1:
			printf("三子棋\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择\n");
			break;
		}
	} while (intput);
}
int main()
{
	test();
	return 0;
}
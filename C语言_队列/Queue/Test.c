#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"
void menu()
{
	printf("+----------------------------+\n");
	printf("| 1.�������      2.���ݳ��� |\n");
	printf("| 3.���ݸ���      0.�˳�     |\n");
	printf("+----------------------------+\n");
}
void Test()
{
	Queue q;
	QueueInit(&q);
	int n = 0, Input = 0, line = 0;
	QDataType x;
	menu();
	do
	{
		printf("��������Ҫ������ѡ�����( 0 - 3 ):>");
		scanf("%d", &Input);
		switch (Input)
		{
		case PUSH:
			printf("��������Ҫ�������ݵĸ���:>");
			scanf("%d", &n);
			printf("����������:>");
			for (int i = 0; i < n; i++)
			{
				scanf("%d", &x);
				QueuePush(&q, x);
			}
			line++;
			break;
		case POP:
			while (!QueueEmpty(&q))
			{
				printf("%d ", QueueFront(&q));
				QueuePop(&q);
			}
			printf("\n");
			line++;
			break;
		case SIZE:
			printf("%d \n", QueueSize(&q));
			break;
		case EXIT:
			QueueDestroy(&q);
			line++;
			break;
		default:
			printf("ѡ����ŷǷ�\n");
			line++;
			break;
		}
	} while (Input);
}
int main()
{
	Test();
	return 0;
}
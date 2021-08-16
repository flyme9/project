#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
void menu()
{
	printf("+----------------------------+\n");
	printf("| 1.������ջ      2.���ݳ�ջ |\n");
	printf("| 3.���ݸ���      0.�˳�     |\n");
	printf("+----------------------------+\n");
}
void Test()
{
	Stack s;
	StackInit(&s);
	int n = 0, Input = 0, line = 0;
	STDataType x;
	menu();
	do
	{
		if (line > 10)
		{
			system("cls");
			menu();
			line = 0;
		}
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
				StackPush(&s, x);
			}
			line++;
			break;
		case POP:
			while (!StackEmpty(&s))
			{
				printf("%d ", StackTop(&s));
				StackPop(&s);
			}
			printf("\n");
			line++;
			break;
		case SIZE:
			 printf("%d \n",StackSize(&s));
			 line++;
			 break;
		case EXIT:
			StackDestroy(&s);
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
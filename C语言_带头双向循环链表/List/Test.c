#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"
void menu()
{
	printf("+----------------------------+\n");
	printf("| 1.β������      2.β��ɾ�� |\n");
	printf("| 3.ͷ������      4.ͷ��ɾ�� |\n");
	printf("| 5.�������      6.���ɾ�� |\n");
	printf("| 7.��������      8.�鿴���� |\n");
	printf("| 9.�޸�����      0.�˳��� |\n");
	printf("+----------------------------+\n");
}
void Test()
{
	ListNode* phead = ListInit();
	int input = 0, line = 0;
	LTDataType x = 0;
	menu();
	do
	{
		if (line > 10)
		{
			system("cls");
			menu();
			line = 0;
		}
		printf("��������Ҫ������ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{

		case PUSHBACK:
			printf("����������Ҫ���������:>");
			scanf("%d", &x);
			ListPushBack(phead, x);
			printf("����ɹ�\n");
			line++;
			break;

		case POPBACK:
			ListPopBack(phead);
			printf("ɾ���ɹ�\n");
			line++;
			break;

		case PUSHFRONT:
			printf("����������Ҫ���������:>");
			scanf("%d", &x);
			ListPushFront(phead, x);
			printf("����ɹ�\n");
			line++;
			break;

		case POPFRONT:
			ListPopFront(phead);
			printf("ɾ���ɹ�\n");
			line++;
			break;

		case INSERT:
			printf("��������ҵ�����x:>");
			scanf("%d", &x);
			ListNode* pos = ListFind(phead, x);
			if (pos != NULL)
			{
				printf("��������������x:>");
				scanf("%d", &x);
				ListInsert(pos, x);
				printf("����ɹ�\n");
			}
			break;

		case ERASE:
			printf("��������ҵ�����x:>");
			scanf("%d", &x);
			pos = ListFind(phead, x);
			if (pos != NULL)
			{
				ListErase(pos);
				printf("ɾ���ɹ�\n");
			}
			line++;
			break;

		case FIND:
			printf("��������ҵ�����x:>");
			scanf("%d", &x);
			pos = ListFind(phead, x);
			if (pos != NULL)
			{
				printf("�����ˣ���ַ��: %p\n", pos);
			}
			else
			{
				printf("���ݲ�����\n");
			}
			line++;
			break;

		case PRINT:
			ListPrint(phead);
			line++;
			break;

		case MODITY:
			printf("��������ҵ�����x:>");
			scanf("%d", &x);
			pos = ListFind(phead, x);
			if (pos != NULL)
			{
				printf("����������x�޸ĺ�ֵ:>");
				scanf("%d", &x);
				ListModity(pos, x);
			}
			line++;
			break;

		case EXIT:
			ListDestory(phead);

		default:
			printf("����ѡ��Υ��\n");
			break;
		}
	} while (input);
}
int main()
{
	Test();
	return 0;
}
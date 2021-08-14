#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
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
	SLTNode* plist = NULL;
	int input = 0, line = 0;
	SListDataType x = 0;
	menu();
	do
	{
		if (line > 5)
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
			SListPushBack(&plist, x);
			printf("����ɹ�\n");
			line++;
			break;

		case POPBACK:
			if (plist == NULL)
			{
				printf("����Ϊ�ձ�\n");
				line++;
				break;
			}
			SListPopBack(&plist);
			printf("ɾ���ɹ�\n");
			line++;
			break;

		case PUSHFRONT:
			printf("����������Ҫ���������:>");
			scanf("%d", &x);
			SListPushFront(&plist, x);
			printf("����ɹ�\n");
			line++;
			break;

		case POPFRONT:
			if (plist == NULL)
			{
				printf("˳���Ϊ�ձ�\n");
				line++;
				break;
			}
			SListPopFront(&plist);
			printf("ɾ���ɹ�\n");
			line++;
			break;

		case INSERT://�������
			if (plist == NULL)
			{
				printf("˳���Ϊ�ձ�\n");
				line++;
				break;
			}
			printf("��������ҵ�����x:>");
			scanf("%d", &x);
			SLTNode* pos = SListFind(plist, x);
			if (pos != NULL)
			{
				printf("��������������x:>");
				scanf("%d", &x);
				SListInsert(pos, x);
				printf("����ɹ�\n");
			}
			line++;
			break;

		case ERASE:
			if (plist == NULL)
			{
				printf("˳���Ϊ�ձ�\n");
				line++;
				break;
			}
			printf("��������ҵ�����x:>");
			scanf("%d", &x);
			pos = SListFind(plist, x);
			if (pos != NULL)
			{
				SListErase(pos);
				printf("ɾ���ɹ�\n");
			}
			line++;
			break;

		case FIND:
			printf("��������ҵ�����x:>");
			scanf("%d", &x);
			pos = SListFind(plist, x);
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
			SListPrint(plist);
			line++;
			break;

		case MODITY:
			if (plist == NULL)
			{
				printf("˳���Ϊ�ձ�\n");
				break;
			}
			printf("��������ҵ�����x:>");
			scanf("%d", &x);
			pos = SListFind(plist, x);
			if (pos != NULL)
			{
				printf("����������x�޸ĺ�ֵ:>");
				scanf("%d", &x);
				SListModity(pos, x);
			}
			line++;
			break;

		case EXIT:
			break;

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
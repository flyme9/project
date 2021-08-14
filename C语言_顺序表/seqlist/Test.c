#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
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
	SL s;
	SeqListInit(&s);
	int input = 0, pos = 0, x = 0, line = 0;
	menu();
	do
	{
		if (line > 10)
		{
			system("cls");
			menu();
			line = 0;
		}
		printf("��������Ҫ���в�����ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case PUSHBACK://β��
			printf("����������Ҫ���������:>");
			scanf("%d", &x);
			SeqListPushBack(&s, x);
			printf("����ɹ�\n");
			line++;
			break;
		case POPBACK://βɾ
			if (s.size == 0)
			{
				printf("˳���Ϊ�ձ�\n");
				line++;
				break;
			}
			SeqListPopBack(&s);
			printf("ɾ���ɹ�\n");
			line++;
			break;
		case PUSHFRONT://ͷ��
			printf("����������Ҫ���������:>");
			scanf("%d", &x);
			SeqListPushFront(&s, x);
			printf("����ɹ�\n");
			line++;
			break;
		case POPFRONT://ͷɾ
			if (s.size == 0)
			{
				printf("˳���Ϊ�ձ�\n");
				line++;
				break;
			}
			SeqListPopFront(&s);
			printf("ɾ���ɹ�\n");
			line++;
			break;
		case INSERT://�������
			printf("������λ��pos������x:>");
			scanf("%d %d", &pos, &x);
			SeqListInsert(&s, pos, x);
			printf("����ɹ�\n");
			line++;
			break;
		case ERASE://���ɾ��
			printf("������λ��pos:>");
			scanf("%d", &pos);
			SeqListErase(&s, pos);
			line++;
			break;
		case FIND://��������
			printf("��������ҵ����� x :>");
			scanf("%d", &x);
			int ret = SeqListFint(&s, x);
			if (ret == -1)
				printf("��������x������\n");
			else
				printf("��������x����\n�±��� %d \n",ret);
			line++;
			break;
		case PRINT://�鿴����
			SeqListPrint(&s);
			line++;
			break;
		case MODITY://�޸�����
			printf("������λ��pos������x:>");
			scanf("%d %d", &pos, &x);
			SeqListModity(&s, pos, x);
			printf("�޸ĳɹ�\n");
			line++;
			break;
		case EXIT:
			SeqListDestoy(&s);
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
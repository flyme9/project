#define _CRT_SECURE_NO_WARNINGS 1
//��ź��ѵ���Ϣ
//��������-�绰-�Ա�-סַ-����
//���Ӻ�����Ϣ
//ɾ��ָ��������Ϣ
//����  �޸�  ����  ��ӡ
#include"contact.h"	
void menu()
{
	printf(" -------------------------------\n");
	printf("|***          ͨѶ¼         ***|\n");
	printf("|**   1.add     |    2.del    **|\n");
	printf("|**   3.search  |    4.modify **|\n");
	printf("|**   5.show    |    6.sort   **|\n");
	printf("|***  7.save    |    0.exit  ***|\n");
	printf("|*******************************|\n");
	printf(" -------------------------------\n");
}
void test()
{
	int input = 0;
	//����ͨѶ¼
	struct Contact con;//con��ͨѶ¼���������dataָ�롢size��capacity		   
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SealedContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case SAVE:
			SaveContact(&con);
			break;
		case EXIT:
			//����ͨѶ¼
			SaveContact(&con);
			DestroyContact(&con);
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("�������ַǷ���������0-6������\a\n");

		}
	} while (input);
}
int main()
{
	test();
	return 0;
}
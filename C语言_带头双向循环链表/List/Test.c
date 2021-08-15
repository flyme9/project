#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"
void menu()
{
	printf("+----------------------------+\n");
	printf("| 1.尾部插入      2.尾部删除 |\n");
	printf("| 3.头部插入      4.头部删除 |\n");
	printf("| 5.随机插入      6.随机删除 |\n");
	printf("| 7.查找数据      8.查看数据 |\n");
	printf("| 9.修改数据      0.退出表单 |\n");
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
		printf("请输入需要操作的选项:>");
		scanf("%d", &input);
		switch (input)
		{

		case PUSHBACK:
			printf("请输入你需要输入的数据:>");
			scanf("%d", &x);
			ListPushBack(phead, x);
			printf("插入成功\n");
			line++;
			break;

		case POPBACK:
			ListPopBack(phead);
			printf("删除成功\n");
			line++;
			break;

		case PUSHFRONT:
			printf("请输入你需要输入的数据:>");
			scanf("%d", &x);
			ListPushFront(phead, x);
			printf("插入成功\n");
			line++;
			break;

		case POPFRONT:
			ListPopFront(phead);
			printf("删除成功\n");
			line++;
			break;

		case INSERT:
			printf("请输入查找的数据x:>");
			scanf("%d", &x);
			ListNode* pos = ListFind(phead, x);
			if (pos != NULL)
			{
				printf("请输入插入的数据x:>");
				scanf("%d", &x);
				ListInsert(pos, x);
				printf("插入成功\n");
			}
			break;

		case ERASE:
			printf("请输入查找的数据x:>");
			scanf("%d", &x);
			pos = ListFind(phead, x);
			if (pos != NULL)
			{
				ListErase(pos);
				printf("删除成功\n");
			}
			line++;
			break;

		case FIND:
			printf("请输入查找的数据x:>");
			scanf("%d", &x);
			pos = ListFind(phead, x);
			if (pos != NULL)
			{
				printf("扎到了，地址是: %p\n", pos);
			}
			else
			{
				printf("数据不存在\n");
			}
			line++;
			break;

		case PRINT:
			ListPrint(phead);
			line++;
			break;

		case MODITY:
			printf("请输入查找的数据x:>");
			scanf("%d", &x);
			pos = ListFind(phead, x);
			if (pos != NULL)
			{
				printf("请输入数据x修改后值:>");
				scanf("%d", &x);
				ListModity(pos, x);
			}
			line++;
			break;

		case EXIT:
			ListDestory(phead);

		default:
			printf("输入选项违法\n");
			break;
		}
	} while (input);
}
int main()
{
	Test();
	return 0;
}
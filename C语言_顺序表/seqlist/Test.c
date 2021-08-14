#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
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
		printf("请输入需要进行操作的选项:>");
		scanf("%d", &input);
		switch (input)
		{
		case PUSHBACK://尾插
			printf("请输入你需要输入的数据:>");
			scanf("%d", &x);
			SeqListPushBack(&s, x);
			printf("插入成功\n");
			line++;
			break;
		case POPBACK://尾删
			if (s.size == 0)
			{
				printf("顺序表为空表\n");
				line++;
				break;
			}
			SeqListPopBack(&s);
			printf("删除成功\n");
			line++;
			break;
		case PUSHFRONT://头插
			printf("请输入你需要输入的数据:>");
			scanf("%d", &x);
			SeqListPushFront(&s, x);
			printf("插入成功\n");
			line++;
			break;
		case POPFRONT://头删
			if (s.size == 0)
			{
				printf("顺序表为空表\n");
				line++;
				break;
			}
			SeqListPopFront(&s);
			printf("删除成功\n");
			line++;
			break;
		case INSERT://随机插入
			printf("请输入位置pos与数据x:>");
			scanf("%d %d", &pos, &x);
			SeqListInsert(&s, pos, x);
			printf("插入成功\n");
			line++;
			break;
		case ERASE://随机删除
			printf("请输入位置pos:>");
			scanf("%d", &pos);
			SeqListErase(&s, pos);
			line++;
			break;
		case FIND://查找数据
			printf("请输入查找的数据 x :>");
			scanf("%d", &x);
			int ret = SeqListFint(&s, x);
			if (ret == -1)
				printf("查找数据x不存在\n");
			else
				printf("查找数据x存在\n下标是 %d \n",ret);
			line++;
			break;
		case PRINT://查看数据
			SeqListPrint(&s);
			line++;
			break;
		case MODITY://修改数据
			printf("请输入位置pos与数据x:>");
			scanf("%d %d", &pos, &x);
			SeqListModity(&s, pos, x);
			printf("修改成功\n");
			line++;
			break;
		case EXIT:
			SeqListDestoy(&s);
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
#define _CRT_SECURE_NO_WARNINGS 1
//存放好友的信息
//包含姓名-电话-性别-住址-年龄
//增加好友信息
//删除指定好友信息
//查找  修改  排序  打印
#include"contact.h"	
void menu()
{
	printf(" -------------------------------\n");
	printf("|***          通讯录         ***|\n");
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
	//创建通讯录
	struct Contact con;//con是通讯录，里面包含data指针、size和capacity		   
	//初始化通讯录
	InitContact(&con);
	do
	{
		menu();
		printf("请选择:>");
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
			//销毁通讯录
			SaveContact(&con);
			DestroyContact(&con);
			printf("退出通讯录\n");
			break;
		default:
			printf("输入数字非法，请输入0-6的数字\a\n");

		}
	} while (input);
}
int main()
{
	test();
	return 0;
}
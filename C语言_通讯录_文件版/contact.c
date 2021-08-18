#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
//姓名查找
static int Find_By_Name(const struct Contact* ps,char name[MAX_NAME])
{
	//找到返回名字所在元素坐标
	//没找到返回 -1
	int i;
	for (i = 0; ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}
	return -1;//找不到
}
//检测容量函数
void CheckCapacity(struct Contact *ps)
{
	if (ps->size == ps->capacity)
	{
		struct PeoInfo *ptr = realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("增容成功\n");
		}
		else
		{
			printf("增容失败\n");
		}
	}
}
//读取文件信息，存放通讯录中
void LoadContact(Contact* ps)
{
	PeoInfo tmp = { 0 };
	FILE* pfRead = fopen("contact.dat", "rb");
	if (pfRead == NULL)
	{
		printf("LoadContact:%s\n", strerror(errno));
		return;
	}
	//读取文件信息，存放到通讯录中
	while (fread(&tmp, sizeof(PeoInfo), 1, pfRead))
	{
		CheckCapacity(ps);
		ps->data[ps->size] = tmp;
		ps->size++;
	}
	fclose(pfRead);
	pfRead = NULL;
}
//初始化通讯录函数
void InitContact(struct Contact *ps)
{
	ps->data = (struct PeoInfo*)malloc(3 * sizeof(struct PeoInfo));
	if (ps->data == NULL)
	{
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
	//把文件中已经存放在通讯录中的信息加载到通讯录中
	LoadContact(ps);
}
//增加通讯录人员信息函数
void AddContact(struct Contact *ps)
{
	//检测当前通讯录的容量
	//1.如果满了，增加空间
	//2.如果没满，不增加
	CheckCapacity(ps);
	//添加通讯录信息
	printf("请输入名字:>");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入性别:>");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入年龄:>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("请输入电话:>");
	scanf("%s", ps->data[ps->size].tele);
	printf("请输入住宅:>");
	scanf("%s", ps->data[ps->size].addr);
	ps->size++;
	printf("添加成功\n");
	Sleep(500);
	system("cls");
}
//查看通讯录函数
void ShowContact(const struct Contact *ps)
{
	if (ps->size == 0)
	{
		//printf("%-8s\t%-5s\t%-5s\t%-15s\t%-20s\n", "姓名", "性别", "年龄", "电话", "住址");
		printf("通讯录为空\n");
		Sleep(500);
		system("cls");
	}
	else
	{
		int i = 0;
		//打印表头
		printf("%-8s\t%-5s\t%-5s\t%-15s\t%-20s\n", "姓名", "性别", "年龄", "电话", "住址");
		//打印信息
		for (i = 0; i < ps->size; i++)
		{
			printf("%-8s\t%-5s\t%-5d\t%-15s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].sex,
				ps->data[i].age,
				ps->data[i].tele,
				ps->data[i].addr);
		}
		Sleep(10000);
		system("cls");
	}
}
//删除通讯录信息函数
void DelContact(struct Contact *ps)
{
	char name[MAX_NAME];
	printf("请输入要删除人的名字:>");
	scanf("%s", name);
	//1.查找删除对象的位置
	
	int pos = Find_By_Name(ps, name);
	//2.删除
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
	}
	else
	{
		int j;
		for (j = pos; j < ps->size ; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
	Sleep(500);
	system("cls");
}
//查找指定通讯录人员的信息
void SealedContact(const struct Contact *ps)
{
	char name[MAX_NAME];
	printf("请输入要查找人的名字:>");
	scanf("%s", name);
	int pos = Find_By_Name(ps, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
		Sleep(500);
		system("cls");
	}
	else
	{
		printf("%-8s\t%-5s\t%-5s\t%-15s\t%-20s\n", "姓名", "性别", "年龄", "电话", "住址");
		printf("%-8s\t%-5s\t%-5d\t%-15s\t%-20s\n",
				ps->data[pos].name,
				ps->data[pos].sex,
				ps->data[pos].age,
				ps->data[pos].tele,
				ps->data[pos].addr);
		Sleep(5000);
		system("cls");
	}
	
}
//修改指定通讯录人员信息
void ModifyContact(struct Contact *ps)
{
	char name[MAX_NAME];
	printf("请输入要修改人的名字:>");
	scanf("%s", name);
	int pos = Find_By_Name(ps, name);
	if (pos == -1)
	{
		printf("要修改人的信息不存在\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", ps->data[pos].name);
		printf("请输入性别:>");
		scanf("%s", ps->data[pos].sex);
		printf("请输入年龄:>");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入电话:>");
		scanf("%s", ps->data[pos].tele);
		printf("请输入住宅:>");
		scanf("%s", ps->data[pos].addr);
		printf("修改完成\n");
	}
	Sleep(500);
	system("cls");
}
//通讯录人员排序(通过姓名排序)
void SortContact(struct Contact *ps)
{
	int i;
	for (i = 0; i < ps->size; i++)
	{	
		int j;
		for (j = 0; j < ps->size - i - 1; j++)
		{
			if (strcmp(ps->data[j].name, ps->data[j + 1].name)>0)
			{
				struct PeoInfo tmp;
				tmp = ps->data[j];
				ps->data[j] = ps->data[j + 1];
				ps->data[j + 1] = tmp;
			}
		}
	}
	printf("排序完成，输入5查看\n");
	Sleep(500);
	system("cls");
}
//退出清空通讯录
void DestroyContact(struct Contact *ps)
{
	free(ps->data);
	ps->data = NULL;
}
//通讯录保存文件函数
void SaveContact(struct Contact *ps)
{
	FILE* pfWrite = fopen("contact.dat", "wb");
	if (pfWrite == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	//写通讯录的数据到文件中
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]), sizeof(PeoInfo), 1, pfWrite);
	}
	fclose(pfWrite);
	pfWrite = NULL;
	printf("保存成功\n");
	Sleep(500);
	system("cls");
}
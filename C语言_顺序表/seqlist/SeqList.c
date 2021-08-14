#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

//初始化顺序表
void SeqListInit(SL* ps)
{
	ps->data = (SeqDataType*)malloc(sizeof(SeqDataType));//给定一个SeqDataType的空间
	ps->size = 0;		//创建为随机值，将其置为0
	ps->capacity = 0;	//创建为随机值，将其置为0
}
//内存判断扩容
void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		//如果capacity为0，则给他4个字节，如果不是，给它2倍的值，同时下面开辟内存每次开辟2倍
		SeqDataType* tmp = realloc(ps->data, sizeof(SeqDataType) * newcapacity);
		if (tmp == NULL)
		{//内存开辟失败情况
			perror("内存开辟失败\n");
			return;
		}
		else
		{
			ps->data = tmp;//将开辟的空间给数组
			ps->capacity = newcapacity;//将开辟后的容量大小给capacity
		}
	}
}
//销毁
void SeqListDestoy(SL* ps)
{
	free(ps->data);//释放空间
	ps->data = NULL;//将指针置空
	ps->size = ps->capacity = 0;//归零
}
//打印顺序表
void SeqListPrint(SL* ps)
{
	for(int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->data[i]);
	}
	printf("\n");
}

//增加数据
//尾插
void SeqListPushBack(SL* ps, SeqDataType x)
{
	SeqListCheckCapacity(ps);//判断内存空间情况
	ps->data[ps->size] = x;//size指向的就是数组尾巴
	ps->size++;//记录数组长度
}
//头插
void SeqListPushFront(SL* ps, SeqDataType x)
{
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;//指向最后一个元素
	while (end >= 0)//当end将下标0位置数组移动后结束循环
	{
		ps->data[end + 1] = ps->data[end];
		end--;
	}
	//移动结束后将数据给0下标
	ps->data[0] = x;
	ps->size++;
}
//在pos位置之前插入
void SeqListInsert(SL* ps, int pos, SeqDataType x)
{
	assert(pos >= 0 && pos <= ps->size);
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;//指向最后一个元素下标
	while (end >= pos)
	{//挪动数据(从后往前)
		ps->data[end + 1] = ps->data[end];
		end--;
	}
	ps->data[pos] = x;
	ps->size++;
}

//删除数据
//尾删
void SeqListPopBack(SL* ps)
{
	assert(ps->size != 0);//如果数组长度为0时，不能进行删除
	ps->size--;//将指针直接指向前一个
}
//头删
void SeqListPopFront(SL* ps)
{
	assert(ps->size != 0);
	int start = 0;
	while (start < ps->size)
	{//挪动数据，从前往后
		ps->data[start] = ps->data[start + 1];
		start++;
	}
	ps->size--;
}
//将pos位置删除
void SeqListErase(SL* ps, int pos)
{
	assert(pos >= 0 && pos < ps->size);
	while (pos <= ps->size)
	{//挪动数据(从前往后)
		ps->data[pos] = ps->data[pos + 1];
		pos++;
	}
	ps->size--;
}

//查找数据
int SeqListFint(SL* ps, SeqDataType x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->data[i] == x)//遍历查找，找到了返回下标
			return i;
	}
	return -1;//没找到返回-1
}

//修改数据
void SeqListModity(SL* ps, int pos,SeqDataType x)
{
	assert(pos >= 0 && pos < ps->size);
	ps->data[pos] = x;
}
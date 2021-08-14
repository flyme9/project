#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<Windows.h>

typedef int SeqDataType;
typedef struct SeqList
{
	SeqDataType* data;	//存储的数据
	int size;			//存储数据的长度
	int capacity;		//内存的状态
}SL;

enum Meun
{
	EXIT,
	PUSHBACK,//尾插
	POPBACK,//尾删
	PUSHFRONT,//头插
	POPFRONT,//头删
	INSERT,//pos前插入
	ERASE,//pos位置删除
	FIND,//查找
	PRINT,//修改
	MODITY//查看
};

//初始化顺序表
void SeqListInit(SL* ps);
//内存判断扩容
void SeqListCheckCapacity(SL* ps);
//销毁
void SeqListDestoy(SL* ps);
//打印顺序表
void SeqListPrint(SL* ps);

//增加数据
//尾插
void SeqListPushBack(SL* ps, SeqDataType x);
//头插
void SeqListPushFront(SL* ps, SeqDataType x);
//在pos位置之前插入
void SeqListInsert(SL* ps, int pos, SeqDataType x);

//删除数据
//尾删
void SeqListPopBack(SL* ps);
//头删
void SeqListPopFront(SL* ps);
//将pos位置删除
void SeqListErase(SL* ps, int pos);

//查找数据
int SeqListFint(SL* ps, SeqDataType x);

//修改数据
void SeqListModity(SL* ps, int pos, SeqDataType x);
#pragma once
#include<stdio.h>	
#include<stdlib.h>
#include<malloc.h>
typedef int SListDataType;
typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;
}SLTNode;

//菜单命名
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

//打印数据
void SListPrint(SLTNode* phead);
//节点申请
SLTNode* BuySListNode(SListDataType x);

//增加数据
//尾插
void SListPushBack(SLTNode** pphead, SListDataType x);
//头插
void SListPushFront(SLTNode** pphead, SListDataType x);
//在pos位置之后插入
void SListInsert(SLTNode* pos, SListDataType x);

//删除数据
//尾删
void SListPopBack(SLTNode** pphead);
//头删
void SListPopFront(SLTNode** pphed);
//在pos位置之后删除
void SListErase(SLTNode* pos);

//查找数据
SLTNode* SListFind(SLTNode* phead, SListDataType x);

//修改数据
void SListModity(SLTNode* pos, SListDataType x);
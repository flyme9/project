#pragma once
#include<stdio.h>	
#include<stdlib.h>
#include<assert.h>
#include<Windows.h>
typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* prev;
	struct ListNode* next;
	LTDataType data;
}ListNode;

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

//初始化
ListNode* ListInit();
//打印
void ListPrint(ListNode* phead);
//申请节点内存
ListNode* BuyListNode(LTDataType x);
//销毁内存
void ListDestory(ListNode* phead);

//增加数据
//尾插
void ListPushBack(ListNode* phead, LTDataType x);
//头插
void ListPushFront(ListNode* phead, LTDataType x);
//pos位置之前插入
void ListInsert(ListNode* pos, LTDataType x);

//删除数据
//尾删
void ListPopBack(ListNode* phead);
//头删
void ListPopFront(ListNode* phead);
//pos位置删除
void ListErase(ListNode* pos);

//查找数据
ListNode* ListFind(ListNode* phead, LTDataType x);

//修改数据
void ListModity(ListNode* pos, LTDataType x);
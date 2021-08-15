#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"
//初始化
ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
//打印
void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
//申请节点内存
ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
//销毁内存
void ListDestory(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}

//增加数据
//尾插
void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* newnode = BuyListNode(x);
	ListNode* tail = phead->prev;//找尾节点
	tail->next = newnode;//尾节点next链接新节点
	newnode->prev = tail;//新节点prev链接尾节点
	newnode->next = phead;//新节点next链接头节点
	phead->prev = newnode;//头节点prev链接新节点
}
//头插
void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* frist = phead->next;//头节点后一个
	ListNode* newnode = BuyListNode(x);
	frist->prev = newnode;//首节点prev链接新节点
	newnode->next = frist;//新节点next链接首节点
	newnode->prev = phead;//新节点prev链接头节点
	phead->next = newnode;//头节点next链接新节点
}
//pos位置之前插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newnode = BuyListNode(x);
	ListNode* prev = pos->prev;//指向pos位置前一个节点
	prev->next = newnode;//pos位置的前一个节点next链接新节点
	newnode->prev = prev;//新节点prev链接前一个节点
	newnode->next = pos;//新节点next链接pos
	pos->prev = newnode;//pos的prev链接新节点
}

//删除数据
//尾删
void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	ListNode* tail = phead->prev;//找尾节点
	ListNode* prev = tail->prev;//保存尾节点上一个节点
	prev->next = phead;//prev的next链接头节点
	phead->prev = prev;//头节点的prev链接尾节点的上一个节点
	free(tail);
	tail = NULL;
}
//头删
void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	ListNode* frist = phead->next;//指向首节点
	ListNode* fristNext = frist->next;//指向首节点下一个节点
	fristNext->prev = phead;//
	phead->next = fristNext;
	free(frist);
	frist = NULL;
}
//pos位置删除
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* posPrev = pos->prev;//pos的上一个节点
	ListNode* posNext = pos->next;//pos的下一个节点
	posPrev->next = posNext;//pos上一个节点next链接pos下一节点
	posNext->prev = posPrev; //pos下一个节点prev链接pos上一节点
}

//查找数据
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;//cur指向首节点
	while (cur != phead)
	{//遍历查找，找了返回数据的指针，否则返回空指针
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

//修改数据
void ListModity(ListNode* pos, LTDataType x)
{//找到pos位置，再将x给pos
	pos->data = x;
}
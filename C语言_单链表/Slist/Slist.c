#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
//打印数据
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	//遍历打印
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;//指向下一个节点
	}
	printf("NULL\n");
}
//申请内存节点
SLTNode* BuySListNode(SListDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

//增加数据
//尾插
void SListPushBack(SLTNode** pphead, SListDataType x)
{
	if (*pphead == NULL)
	{	//如果链表尾空，则开辟一个节点存入数据
		SLTNode* newnode = BuySListNode(x);
		*pphead = newnode;
	}
	else
	{
		//SLTNode* tail = *pphead;
		//while (tail->next != NULL)
		//{	//找到尾巴
		//	tail = tail->next;//将下一个节点给tail
		//}
		//SLTNode* newnode = BuySListNode(x);
		//tail->next = newnode;//将尾节点指针指向下一个节点
		//newnode->next = NULL;//将新节点指针指向空
		SListInsert(*pphead, x);
	}
}
//头插
void SListPushFront(SLTNode** pphead, SListDataType x)
{
	SLTNode* newnode = BuySListNode(x);
	newnode->next = *pphead;//新节点指针存储第一个节点的地址
	*pphead = newnode;//然后将新节点作为第一个节点，用pphead指向它
}
//在pos位置之后插入
void SListInsert(SLTNode* pos, SListDataType x)
{
	SLTNode* newnode = BuySListNode(x);
	SLTNode* next = pos->next;//
	newnode->next = next;//将新节点的指针存储pos下一个节点的地址
	pos->next = newnode;//然后pos指向的节点存储新节点的地址
}

//删除数据
//尾删
void SListPopBack(SLTNode** pphead)
{
	//如果链表为空则直接返回
	if (*pphead == NULL)
		return;
	else if ((*pphead)->next == NULL)
	{//如果链表只有一个节点，pphead指向的就是第一个节点，直接释放并置空
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//SLTNode* prev = NULL;	//指向尾节点前一个节点
		//SLTNode* tail = *pphead;//指向尾节点
		//while (tail->next != NULL)
		//{	//找到链表的尾节点和尾节点前面一个节点
		//	prev = tail;
		//	tail = tail->next;
		//}
		//free(tail);//释放掉最后一个节点
		//prev->next = NULL;//将尾节点的前一个节点的指针指向空
		SListErase(*pphead);
	}
}
//头删
void SListPopFront(SLTNode** pphead)
{
	//如果链表节点为空，直接返回
	if (*pphead == NULL)
		return;
	else
	{//如果链表有1个以上节点
		SLTNode* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}
}
//在pos位置之后删除
void SListErase(SLTNode* pos)
{
	if (pos->next != NULL)
	{
		SLTNode* next = pos->next;//指向pos之后的节点
		SLTNode* nextnext = next->next;//指向pos之后的节点的下一个节点
		pos->next = nextnext;
		free(next);
	}
}

//查找数据
SLTNode* SListFind(SLTNode* phead, SListDataType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//修改数据
void SListModity(SLTNode* pos, SListDataType x)
{
	pos->data = x;
}
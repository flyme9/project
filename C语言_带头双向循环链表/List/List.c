#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"
//��ʼ��
ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
//��ӡ
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
//����ڵ��ڴ�
ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
//�����ڴ�
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

//��������
//β��
void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* newnode = BuyListNode(x);
	ListNode* tail = phead->prev;//��β�ڵ�
	tail->next = newnode;//β�ڵ�next�����½ڵ�
	newnode->prev = tail;//�½ڵ�prev����β�ڵ�
	newnode->next = phead;//�½ڵ�next����ͷ�ڵ�
	phead->prev = newnode;//ͷ�ڵ�prev�����½ڵ�
}
//ͷ��
void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* frist = phead->next;//ͷ�ڵ��һ��
	ListNode* newnode = BuyListNode(x);
	frist->prev = newnode;//�׽ڵ�prev�����½ڵ�
	newnode->next = frist;//�½ڵ�next�����׽ڵ�
	newnode->prev = phead;//�½ڵ�prev����ͷ�ڵ�
	phead->next = newnode;//ͷ�ڵ�next�����½ڵ�
}
//posλ��֮ǰ����
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newnode = BuyListNode(x);
	ListNode* prev = pos->prev;//ָ��posλ��ǰһ���ڵ�
	prev->next = newnode;//posλ�õ�ǰһ���ڵ�next�����½ڵ�
	newnode->prev = prev;//�½ڵ�prev����ǰһ���ڵ�
	newnode->next = pos;//�½ڵ�next����pos
	pos->prev = newnode;//pos��prev�����½ڵ�
}

//ɾ������
//βɾ
void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	ListNode* tail = phead->prev;//��β�ڵ�
	ListNode* prev = tail->prev;//����β�ڵ���һ���ڵ�
	prev->next = phead;//prev��next����ͷ�ڵ�
	phead->prev = prev;//ͷ�ڵ��prev����β�ڵ����һ���ڵ�
	free(tail);
	tail = NULL;
}
//ͷɾ
void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	ListNode* frist = phead->next;//ָ���׽ڵ�
	ListNode* fristNext = frist->next;//ָ���׽ڵ���һ���ڵ�
	fristNext->prev = phead;//
	phead->next = fristNext;
	free(frist);
	frist = NULL;
}
//posλ��ɾ��
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* posPrev = pos->prev;//pos����һ���ڵ�
	ListNode* posNext = pos->next;//pos����һ���ڵ�
	posPrev->next = posNext;//pos��һ���ڵ�next����pos��һ�ڵ�
	posNext->prev = posPrev; //pos��һ���ڵ�prev����pos��һ�ڵ�
}

//��������
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;//curָ���׽ڵ�
	while (cur != phead)
	{//�������ң����˷������ݵ�ָ�룬���򷵻ؿ�ָ��
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

//�޸�����
void ListModity(ListNode* pos, LTDataType x)
{//�ҵ�posλ�ã��ٽ�x��pos
	pos->data = x;
}
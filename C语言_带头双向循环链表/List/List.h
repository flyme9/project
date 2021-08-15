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
	PUSHBACK,//β��
	POPBACK,//βɾ
	PUSHFRONT,//ͷ��
	POPFRONT,//ͷɾ
	INSERT,//posǰ����
	ERASE,//posλ��ɾ��
	FIND,//����
	PRINT,//�޸�
	MODITY//�鿴
};

//��ʼ��
ListNode* ListInit();
//��ӡ
void ListPrint(ListNode* phead);
//����ڵ��ڴ�
ListNode* BuyListNode(LTDataType x);
//�����ڴ�
void ListDestory(ListNode* phead);

//��������
//β��
void ListPushBack(ListNode* phead, LTDataType x);
//ͷ��
void ListPushFront(ListNode* phead, LTDataType x);
//posλ��֮ǰ����
void ListInsert(ListNode* pos, LTDataType x);

//ɾ������
//βɾ
void ListPopBack(ListNode* phead);
//ͷɾ
void ListPopFront(ListNode* phead);
//posλ��ɾ��
void ListErase(ListNode* pos);

//��������
ListNode* ListFind(ListNode* phead, LTDataType x);

//�޸�����
void ListModity(ListNode* pos, LTDataType x);
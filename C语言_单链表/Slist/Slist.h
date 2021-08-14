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

//�˵�����
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

//��ӡ����
void SListPrint(SLTNode* phead);
//�ڵ�����
SLTNode* BuySListNode(SListDataType x);

//��������
//β��
void SListPushBack(SLTNode** pphead, SListDataType x);
//ͷ��
void SListPushFront(SLTNode** pphead, SListDataType x);
//��posλ��֮�����
void SListInsert(SLTNode* pos, SListDataType x);

//ɾ������
//βɾ
void SListPopBack(SLTNode** pphead);
//ͷɾ
void SListPopFront(SLTNode** pphed);
//��posλ��֮��ɾ��
void SListErase(SLTNode* pos);

//��������
SLTNode* SListFind(SLTNode* phead, SListDataType x);

//�޸�����
void SListModity(SLTNode* pos, SListDataType x);
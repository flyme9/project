#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<Windows.h>

typedef int SeqDataType;
typedef struct SeqList
{
	SeqDataType* data;	//�洢������
	int size;			//�洢���ݵĳ���
	int capacity;		//�ڴ��״̬
}SL;

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

//��ʼ��˳���
void SeqListInit(SL* ps);
//�ڴ��ж�����
void SeqListCheckCapacity(SL* ps);
//����
void SeqListDestoy(SL* ps);
//��ӡ˳���
void SeqListPrint(SL* ps);

//��������
//β��
void SeqListPushBack(SL* ps, SeqDataType x);
//ͷ��
void SeqListPushFront(SL* ps, SeqDataType x);
//��posλ��֮ǰ����
void SeqListInsert(SL* ps, int pos, SeqDataType x);

//ɾ������
//βɾ
void SeqListPopBack(SL* ps);
//ͷɾ
void SeqListPopFront(SL* ps);
//��posλ��ɾ��
void SeqListErase(SL* ps, int pos);

//��������
int SeqListFint(SL* ps, SeqDataType x);

//�޸�����
void SeqListModity(SL* ps, int pos, SeqDataType x);
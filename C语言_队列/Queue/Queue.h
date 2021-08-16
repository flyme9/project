#pragma once
#include<stdio.h>
#include<assert.h> 
#include<stdlib.h>
#include<stdbool.h>
typedef int QDataType;
//����ṹ����ʾ����
typedef struct QListNode
{
	QDataType data;//����
	struct QListNode* next;//ָ����һ����ָ��
}QNode;
//���л���
typedef struct Queue
{
	QNode* head;//��ͷ
	QNode* tail;//��β
}Queue;
enum menu
{
	EXIT,//�˳�
	PUSH,//��ջ
	POP,//��ջ
	SIZE//ջ���ݸ���
};
//��ʼ��
void QueueInit(Queue* pq);
//���ٶ���
void QueueDestroy(Queue* pq);
//��β���
void QueuePush(Queue* pq, QDataType x);
//��ͷ����
void QueuePop(Queue* pq);
//��ȡ��ͷ����
QDataType QueueFront(Queue* pq);
//��ȡ��β����
QDataType QueueBack(Queue* pq);
//��ȡ������Ч���ݸ���
int QueueSize(Queue* pq);
//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);
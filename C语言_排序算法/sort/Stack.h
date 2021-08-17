#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int STDataType;
typedef struct Stack
{
	STDataType* arr;//�洢����
	int top;//ջ��
	int capacity;//����
}Stack;
enum menu
{
	EXIT,//�˳�
	PUSH,//��ջ
	POP,//��ջ
	SIZE//ջ���ݸ���
};
//��ʼ��
void StackInit(Stack* ps);
//ջ����
void StackDestroy(Stack* ps);
//��ջ
void StackPush(Stack* ps, STDataType x);
//��ջ
void StackPop(Stack* ps);
//��ȡջ��Ԫ��
STDataType StackTop(Stack* ps);
//��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps);
//���ջ�Ƿ�Ϊ��
bool StackEmpty(Stack* ps);
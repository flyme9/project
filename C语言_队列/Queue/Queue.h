#pragma once
#include<stdio.h>
#include<assert.h> 
#include<stdlib.h>
#include<stdbool.h>
typedef int QDataType;
//链表结构：表示队列
typedef struct QListNode
{
	QDataType data;//数据
	struct QListNode* next;//指向下一个的指针
}QNode;
//队列机构
typedef struct Queue
{
	QNode* head;//队头
	QNode* tail;//队尾
}Queue;
enum menu
{
	EXIT,//退出
	PUSH,//入栈
	POP,//出栈
	SIZE//栈数据个数
};
//初始化
void QueueInit(Queue* pq);
//销毁队列
void QueueDestroy(Queue* pq);
//队尾入队
void QueuePush(Queue* pq, QDataType x);
//队头出队
void QueuePop(Queue* pq);
//获取队头数据
QDataType QueueFront(Queue* pq);
//获取队尾数据
QDataType QueueBack(Queue* pq);
//获取队列有效数据个数
int QueueSize(Queue* pq);
//判断队列是否为空
bool QueueEmpty(Queue* pq);
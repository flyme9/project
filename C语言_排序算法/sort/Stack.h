#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int STDataType;
typedef struct Stack
{
	STDataType* arr;//存储数据
	int top;//栈顶
	int capacity;//容量
}Stack;
enum menu
{
	EXIT,//退出
	PUSH,//入栈
	POP,//出栈
	SIZE//栈数据个数
};
//初始化
void StackInit(Stack* ps);
//栈销毁
void StackDestroy(Stack* ps);
//入栈
void StackPush(Stack* ps, STDataType x);
//出栈
void StackPop(Stack* ps);
//获取栈顶元素
STDataType StackTop(Stack* ps);
//获取栈中有效元素个数
int StackSize(Stack* ps);
//检测栈是否为空
bool StackEmpty(Stack* ps);
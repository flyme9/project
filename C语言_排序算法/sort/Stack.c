#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
//初始化
void StackInit(Stack* ps)
{	//初始化给定四个字节空间
	ps->arr = (STDataType*)malloc(sizeof(STDataType) * 4);
	//判断空间开辟是否成功
	if (ps->arr == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	ps->top = 0;
	ps->capacity = 4;
}//栈销毁
void StackDestroy(Stack* ps)
{	
	assert(ps);
	free(ps->arr);//释放
	ps->arr = NULL;//置空指针
	ps->top = ps->capacity = 0;//置0
}
//入栈
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{//空间满了要扩容
		STDataType* tmp = realloc(ps->arr, sizeof(STDataType) * 2 * ps->capacity);
		//判断内存是否开辟成功
		if (tmp == NULL)
		{
			perror("realloc fail\n");
			exit(-1);
		}
		else
		{
			ps->arr = tmp;
			ps->capacity *= 2;
		}
	}
	ps->arr[ps->top] = x;
	ps->top++;
}
//出栈
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);//栈空了，调用报错，终止程序
	ps->top--;
}
//获取栈顶元素
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);//栈空了，调用报错，终止程序
	return ps->arr[ps->top-1];
}
//获取栈中有效元素个数
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
//检测栈是否为空
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;//等于0为空，非0表示栈内有数据
}
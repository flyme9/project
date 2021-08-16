#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
//��ʼ��
void StackInit(Stack* ps)
{	//��ʼ�������ĸ��ֽڿռ�
	ps->arr = (STDataType*)malloc(sizeof(STDataType) * 4);
	//�жϿռ俪���Ƿ�ɹ�
	if (ps->arr == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	ps->top = 0;
	ps->capacity = 4;
}//ջ����
void StackDestroy(Stack* ps)
{	
	assert(ps);
	free(ps->arr);//�ͷ�
	ps->arr = NULL;//�ÿ�ָ��
	ps->top = ps->capacity = 0;//��0
}
//��ջ
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{//�ռ�����Ҫ����
		STDataType* tmp = realloc(ps->arr, sizeof(STDataType) * 2 * ps->capacity);
		//�ж��ڴ��Ƿ񿪱ٳɹ�
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
//��ջ
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);//ջ���ˣ����ñ�����ֹ����
	ps->top--;
}
//��ȡջ��Ԫ��
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);//ջ���ˣ����ñ�����ֹ����
	return ps->arr[ps->top-1];
}
//��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
//���ջ�Ƿ�Ϊ��
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;//����0Ϊ�գ���0��ʾջ��������
}
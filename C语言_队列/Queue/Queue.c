#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"
//初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}
//销毁队列
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;//保存cur下一个节点
		free(cur);//释放
		cur = next;//cur指向它的下一个节点
	}
	//所有节点释放后，将头尾指针置为空指针
	pq->head = pq->tail = NULL;
}
//队尾入队
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	//开辟空间
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	if (pq->tail == NULL)
		pq->head = pq->tail = newnode;//如果没有节点，直接链接
	else
	{
		pq->tail->next = newnode;//有节点，尾节点next链接
		pq->tail = newnode;//然后尾指针指向newnode
	}
}
//队头出队
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	if (pq->head->next == NULL)
	{//一个节点的情况
		free(pq->head);//头尾指向同一个空间，直接释放
		pq->head = pq->tail = NULL;//
	}
	else
	{//多个节点的情况
		QNode* next = pq->head->next;//保存头节点的下一个节点
		free(pq->head);//释放
		pq->head = next;//头节点指向下一个节点
	}
}
//获取队头数据
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;
}
//获取队尾数据
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->tail->data;
}
//获取队列有效数据个数
int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QNode* cur = pq->head;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}
//判断队列是否为空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}
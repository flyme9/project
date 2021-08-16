#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"
//��ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}
//���ٶ���
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;//����cur��һ���ڵ�
		free(cur);//�ͷ�
		cur = next;//curָ��������һ���ڵ�
	}
	//���нڵ��ͷź󣬽�ͷβָ����Ϊ��ָ��
	pq->head = pq->tail = NULL;
}
//��β���
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	//���ٿռ�
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	if (pq->tail == NULL)
		pq->head = pq->tail = newnode;//���û�нڵ㣬ֱ������
	else
	{
		pq->tail->next = newnode;//�нڵ㣬β�ڵ�next����
		pq->tail = newnode;//Ȼ��βָ��ָ��newnode
	}
}
//��ͷ����
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	if (pq->head->next == NULL)
	{//һ���ڵ�����
		free(pq->head);//ͷβָ��ͬһ���ռ䣬ֱ���ͷ�
		pq->head = pq->tail = NULL;//
	}
	else
	{//����ڵ�����
		QNode* next = pq->head->next;//����ͷ�ڵ����һ���ڵ�
		free(pq->head);//�ͷ�
		pq->head = next;//ͷ�ڵ�ָ����һ���ڵ�
	}
}
//��ȡ��ͷ����
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;
}
//��ȡ��β����
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->tail->data;
}
//��ȡ������Ч���ݸ���
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
//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}
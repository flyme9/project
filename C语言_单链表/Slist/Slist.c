#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
//��ӡ����
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	//������ӡ
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;//ָ����һ���ڵ�
	}
	printf("NULL\n");
}
//�����ڴ�ڵ�
SLTNode* BuySListNode(SListDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

//��������
//β��
void SListPushBack(SLTNode** pphead, SListDataType x)
{
	if (*pphead == NULL)
	{	//�������β�գ��򿪱�һ���ڵ��������
		SLTNode* newnode = BuySListNode(x);
		*pphead = newnode;
	}
	else
	{
		//SLTNode* tail = *pphead;
		//while (tail->next != NULL)
		//{	//�ҵ�β��
		//	tail = tail->next;//����һ���ڵ��tail
		//}
		//SLTNode* newnode = BuySListNode(x);
		//tail->next = newnode;//��β�ڵ�ָ��ָ����һ���ڵ�
		//newnode->next = NULL;//���½ڵ�ָ��ָ���
		SListInsert(*pphead, x);
	}
}
//ͷ��
void SListPushFront(SLTNode** pphead, SListDataType x)
{
	SLTNode* newnode = BuySListNode(x);
	newnode->next = *pphead;//�½ڵ�ָ��洢��һ���ڵ�ĵ�ַ
	*pphead = newnode;//Ȼ���½ڵ���Ϊ��һ���ڵ㣬��ppheadָ����
}
//��posλ��֮�����
void SListInsert(SLTNode* pos, SListDataType x)
{
	SLTNode* newnode = BuySListNode(x);
	SLTNode* next = pos->next;//
	newnode->next = next;//���½ڵ��ָ��洢pos��һ���ڵ�ĵ�ַ
	pos->next = newnode;//Ȼ��posָ��Ľڵ�洢�½ڵ�ĵ�ַ
}

//ɾ������
//βɾ
void SListPopBack(SLTNode** pphead)
{
	//�������Ϊ����ֱ�ӷ���
	if (*pphead == NULL)
		return;
	else if ((*pphead)->next == NULL)
	{//�������ֻ��һ���ڵ㣬ppheadָ��ľ��ǵ�һ���ڵ㣬ֱ���ͷŲ��ÿ�
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//SLTNode* prev = NULL;	//ָ��β�ڵ�ǰһ���ڵ�
		//SLTNode* tail = *pphead;//ָ��β�ڵ�
		//while (tail->next != NULL)
		//{	//�ҵ������β�ڵ��β�ڵ�ǰ��һ���ڵ�
		//	prev = tail;
		//	tail = tail->next;
		//}
		//free(tail);//�ͷŵ����һ���ڵ�
		//prev->next = NULL;//��β�ڵ��ǰһ���ڵ��ָ��ָ���
		SListErase(*pphead);
	}
}
//ͷɾ
void SListPopFront(SLTNode** pphead)
{
	//�������ڵ�Ϊ�գ�ֱ�ӷ���
	if (*pphead == NULL)
		return;
	else
	{//���������1�����Ͻڵ�
		SLTNode* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}
}
//��posλ��֮��ɾ��
void SListErase(SLTNode* pos)
{
	if (pos->next != NULL)
	{
		SLTNode* next = pos->next;//ָ��pos֮��Ľڵ�
		SLTNode* nextnext = next->next;//ָ��pos֮��Ľڵ����һ���ڵ�
		pos->next = nextnext;
		free(next);
	}
}

//��������
SLTNode* SListFind(SLTNode* phead, SListDataType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//�޸�����
void SListModity(SLTNode* pos, SListDataType x)
{
	pos->data = x;
}
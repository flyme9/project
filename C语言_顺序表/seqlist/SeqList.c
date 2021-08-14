#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

//��ʼ��˳���
void SeqListInit(SL* ps)
{
	ps->data = (SeqDataType*)malloc(sizeof(SeqDataType));//����һ��SeqDataType�Ŀռ�
	ps->size = 0;		//����Ϊ���ֵ��������Ϊ0
	ps->capacity = 0;	//����Ϊ���ֵ��������Ϊ0
}
//�ڴ��ж�����
void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		//���capacityΪ0�������4���ֽڣ�������ǣ�����2����ֵ��ͬʱ���濪���ڴ�ÿ�ο���2��
		SeqDataType* tmp = realloc(ps->data, sizeof(SeqDataType) * newcapacity);
		if (tmp == NULL)
		{//�ڴ濪��ʧ�����
			perror("�ڴ濪��ʧ��\n");
			return;
		}
		else
		{
			ps->data = tmp;//�����ٵĿռ������
			ps->capacity = newcapacity;//�����ٺ��������С��capacity
		}
	}
}
//����
void SeqListDestoy(SL* ps)
{
	free(ps->data);//�ͷſռ�
	ps->data = NULL;//��ָ���ÿ�
	ps->size = ps->capacity = 0;//����
}
//��ӡ˳���
void SeqListPrint(SL* ps)
{
	for(int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->data[i]);
	}
	printf("\n");
}

//��������
//β��
void SeqListPushBack(SL* ps, SeqDataType x)
{
	SeqListCheckCapacity(ps);//�ж��ڴ�ռ����
	ps->data[ps->size] = x;//sizeָ��ľ�������β��
	ps->size++;//��¼���鳤��
}
//ͷ��
void SeqListPushFront(SL* ps, SeqDataType x)
{
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;//ָ�����һ��Ԫ��
	while (end >= 0)//��end���±�0λ�������ƶ������ѭ��
	{
		ps->data[end + 1] = ps->data[end];
		end--;
	}
	//�ƶ����������ݸ�0�±�
	ps->data[0] = x;
	ps->size++;
}
//��posλ��֮ǰ����
void SeqListInsert(SL* ps, int pos, SeqDataType x)
{
	assert(pos >= 0 && pos <= ps->size);
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;//ָ�����һ��Ԫ���±�
	while (end >= pos)
	{//Ų������(�Ӻ���ǰ)
		ps->data[end + 1] = ps->data[end];
		end--;
	}
	ps->data[pos] = x;
	ps->size++;
}

//ɾ������
//βɾ
void SeqListPopBack(SL* ps)
{
	assert(ps->size != 0);//������鳤��Ϊ0ʱ�����ܽ���ɾ��
	ps->size--;//��ָ��ֱ��ָ��ǰһ��
}
//ͷɾ
void SeqListPopFront(SL* ps)
{
	assert(ps->size != 0);
	int start = 0;
	while (start < ps->size)
	{//Ų�����ݣ���ǰ����
		ps->data[start] = ps->data[start + 1];
		start++;
	}
	ps->size--;
}
//��posλ��ɾ��
void SeqListErase(SL* ps, int pos)
{
	assert(pos >= 0 && pos < ps->size);
	while (pos <= ps->size)
	{//Ų������(��ǰ����)
		ps->data[pos] = ps->data[pos + 1];
		pos++;
	}
	ps->size--;
}

//��������
int SeqListFint(SL* ps, SeqDataType x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->data[i] == x)//�������ң��ҵ��˷����±�
			return i;
	}
	return -1;//û�ҵ�����-1
}

//�޸�����
void SeqListModity(SL* ps, int pos,SeqDataType x)
{
	assert(pos >= 0 && pos < ps->size);
	ps->data[pos] = x;
}
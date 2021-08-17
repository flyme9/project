#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
#include"Stack.h"
//����
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//��ӡ
void PrintArray(int* arr, int n)
{
	//��ӡ����
	for (int i = 0; i <n; i++)
	//��ӡ����
	//for(int i=n-1;i>=0;i--)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
// ��������
void InsertSort(int* arr, int n)
{	
	//[0, end]����  end+1λ�õ�ֵ����[0, end]����[0, end+1]����
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		//ָ���i��Ԫ��
		int tmp = arr[end + 1];
		//����end��һ��Ԫ�ص�ֵ
		while (end >= 0)
		{
			if (arr[end] > tmp)
			{//endָ��Ԫ�ش���tmp����endָ���Ԫ������Ų
				arr[end + 1] = arr[end];
				end--;
			}
			else
				break;
			//���endָ���Ԫ��С�ڵ���tmp������Ҫ����Ų��Ԫ��
		}
		//endΪ--��ķ���ֵ
		//�ҵ�λ�ú󣬲�����endָ��Ԫ�غ�һ��λ��
		arr[end + 1] = tmp;
	}
}
// ϣ������
void ShellSort(int* arr, int n)
{
	int gap=n;//���鳤��
	while (gap > 1)
	{
		gap /= 2;
		//���Ϊ1
		gap = gap / 3 + 1;
		//���Ϊ0����Ϊ1��Ϊ0ʱ����δ��ɣ�����+1
		//gap==1ʱ��Ϊֱ�Ӳ�������
		//gap>1ʱ��ΪԤ����

		//
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			//ָ���i��Ԫ��
			int tmp = arr[end + gap];
			//��������gap������Ԫ��
			while (end >= 0)
			{
				if (arr[end] > arr[end + gap])
				{	//Ų��Ԫ��
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
					break;
			}
			//��tmp��end+gapλ��
			arr[end + gap] = tmp;
		}
	}
}
// ѡ������
void SelectSort(int* arr, int n)
{
	//for (int i = 0; i < n-1; i++)
	//{
	//	int min = i;
	//	for (int j = i+1; j < n; j++)
	//	{
	//		if (arr[min] > arr[j])
	//		{	//���min����jλ�õ�ֵ�����н���
	//			Swap(&arr[min], &arr[j]);
	//		}
	//	}
	//}
	//�Ż���˫ָ��
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int min = begin, max = begin;
		for (int i = begin; i <= end; i++)
		{
			if (arr[i] < arr[min])
				min = i;
			if (arr[i] > arr[max])
				max = i;
		}
		Swap(&arr[begin], &arr[min]);
		if (begin == max)
			max = min;
		Swap(&arr[max], &arr[end]);
		begin++;
		end--;
	}
}
// ������
void AdjustDwon(int* arr, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;//�����ӿ�ʼ
	while (child < n)
	{
		//if (child + 1 < n&&arr[child + 1] < arr[child])
		//{
		//	child++;
		//}
		//if (arr[child] < arr[parent])
		//{
		//	//������ӱȸ���С������λ��
		//	Swap(&arr[child], &arr[parent]);
		//	parent = child;//������ָ���Ԫ�ظ�����
		//	child = parent * 2 + 1;//��һ������������
		//}
		//else
		//{
		//	break;
		//}

		//�����,ѡ�����Һ����д���Ǹ�
		if (child + 1 < n&&arr[child + 1] > arr[child])
			child++;
		if (arr[child] > arr[parent])
		{
			//������ӱȸ��״󣬽���λ��
			Swap(&arr[child], &arr[parent]);
			parent = child;//������ָ���Ԫ�ظ�����
			child = parent * 2 + 1;//��һ������������
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* arr, int n)
{
	//����
	//�����һ�������ķ�Ҷ�ڵ���������е���
	for (int i = (n - 2) / 2; i >= 0; i--)
		AdjustDwon(arr, n, i);
	//������,�����
	int end = n - 1;
	while (end > 0)
	{
		//������Ԫ�طŵ����
		Swap(&arr[0], &arr[end]);
		AdjustDwon(arr, end, 0);
		end--;
	}
}
// ð������
void BubbleSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)//����n-1��ð������
	{
		int falg = 0;
		for (int j = 0; j < n - 1 - i; j++)//ÿ�˽���n-1-i�αȽ�
		{
			if (arr[j] > arr[j+1])
				//���ǰһ���Ⱥ�һ���󣬽��н���
				Swap(&arr[j], &arr[j+1]);
			falg = 1;
		}
		if (falg == 0)
			break;
	}
}
// ��������
//����ȡ��
int GetMidIndex(int* arr, int left, int right)
{
	int mid = (left + right) >> 1;
	if (arr[left] < arr[mid])
	{
		//�м�ֵ������ߣ������ұ�
		//left < mid <right
		if (arr[mid] < arr[right])
			return mid;
		//right < left < mid
		else if (arr[left] > arr[right])
			return left;
		//left < right < mid
		else
			return right;
	}
	//left > mid
	else
	{
		//left > mid > right
		if (arr[mid] > arr[right])
			return mid;
		//right > left > mid
		else if (arr[left] < arr[right])
			return left;
		//left > right > mid
		else
			return right;	
	}
}
//�ڿӷ�
int PartSort1(int* arr, int left, int right)
{
	//ȡ�м�ֵ
	int index = GetMidIndex(arr, left, right);
	//������ֵ���м�ֵλ��
	Swap(&arr[left], &arr[right]);
	int begin = left, end = right;
	int pivot = begin;
	int key = arr[begin];
	while (begin < end)
	{
		// �ұ���С���ŵ����
		while (begin < end && arr[end] >= key)
			--end;
		// С�ķŵ���ߵĿ���Լ��γ��µĿ�λ
		arr[pivot] = arr[end];
		pivot = end;
		// ����Ҵ�
		while (begin < end && arr[begin] <= key)
			++begin;
		// ��ķŵ���ߵĿ���Լ��γ��µĿ�λ
		arr[pivot] = arr[begin];
		pivot = begin;
	}
	pivot = begin;
	arr[pivot] = key;
	return pivot;//���ؿӵ�λ��
}
int PartSort2(int* arr, int left, int right)
{
	int index = GetMidIndex(arr, left, right);
	Swap(&arr[left], &arr[index]);
	int begin = left, end = right;
	int key = begin;
	while (begin < end)
	{
		//�ұ���С
		while (begin < end&&arr[end] >= arr[key])
			end--;
		//����Ҵ�
		while (begin < end&&arr[begin] <= arr[key])
			begin++;
		//����
		Swap(&arr[begin], &arr[end]);
	}
	//key��begin����
	Swap(&arr[begin], &arr[key]);
	return begin;
}
//ǰ��ָ�뷨
int PartSort3(int* arr, int left, int right)
{
	int index = GetMidIndex(arr, left, right);
	Swap(&arr[left], &arr[index]);
	int key = left;
	int prev = left, cur = left + 1;
	while (cur <= right)
	{
		//С�Ļ�����ߣ�++prev!=cur��ֹprev��curָ��ͬһ��λ��Ҳ���н���
		if (arr[cur] < arr[key]&&++prev!=cur)
		{
			//С�ڣ�����
			Swap(&arr[prev], &arr[cur]);
		}
		//��С�ڣ�cur������
		cur++;
	}
	//��key��prev����
	Swap(&arr[key], &arr[prev]);
	return prev;
}
void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
		return;
	int keyIndex = PartSort3(arr, left, right);
	//������[left,pivot-1]
	//��piovt
	//������[pivot+1,right]
	// С����
	if (keyIndex - 1 - left > 100)
		QuickSort(arr, left, keyIndex - 1);
	else
		InsertSort(arr + left, keyIndex - 1 - left + 1);
	if (right - (keyIndex + 1) > 100)
		QuickSort(arr, keyIndex + 1, right);
	else
		InsertSort(arr + keyIndex + 1, right - (keyIndex + 1) + 1);
}
void QuickSort2(int* arr, int left, int right)
{
	if (left < right)
	{
		int pivot = arr[left];//�����׼��
		int leftCur = left+1;
		int rightCur = right;
		while (leftCur < rightCur)
		{
			if (arr[leftCur] > pivot)
			{
				//��߷űȻ�׼��С�������ұ߷űȻ�׼�������
				Swap(&arr[leftCur], &arr[rightCur]);
				rightCur--;
			}
			else
			{
				leftCur++;
			}
		}
		if (arr[leftCur] >= pivot)
			leftCur--;
		Swap(&arr[left], &arr[leftCur]);
		QuickSort2(arr, left, leftCur);
		QuickSort2(arr, rightCur, right);
	}
}
void QuickSortNonR(int* a, int n)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, n - 1);
	StackPush(&st, 0);

	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);
		StackPop(&st);

		int right = StackTop(&st);
		StackPop(&st);

		int keyIndex = PartSort1(a, left, right);
		// [left, keyIndex-1] keyIndex [keyIndex+1, right]

		if (keyIndex + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, keyIndex + 1);
		}

		if (left < keyIndex - 1)
		{
			StackPush(&st, keyIndex - 1);
			StackPush(&st, left);
		}
	}

	StackDestroy(&st);
}
// �鲢����
void _MergeSort(int* arr, int left, int right, int* tmp)
{
	if (left >= right)
		return;
	//������м�ָ��
	//�ֽ�
	int mid = (left + right) >> 1;
	_MergeSort(arr, left, mid, tmp);
	_MergeSort(arr, mid + 1, right, tmp);
	//�鲢
	int begin1 = left, end1 = mid;//������
	int begin2 = mid + 1, end2 = right;//������
	int index = left;
	//����һ�������ͽ���
	while (begin1 <= end1&&begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
			tmp[index++] = arr[begin1++];
		else
			tmp[index++] = arr[begin2++];
	}
	//begin1������Ԫ��
	while (begin1 <= end1)
		tmp[index++] = arr[begin1++];
	//begin2������Ԫ��
	while (begin2 <= end2)
		tmp[index++] = arr[begin2++];
	//�����Ժ󣬿�����ԭ����
	for (int i = 0; i <= right; i++)
		arr[i] = tmp[i];
}
void MergeSort(int* arr, int n)
{
	//�����������
	//�Ұ���������
	//�鲢�����ζԱȣ�ȡС�ķŵ���ʱ������
	//��ʱ�������򣬿���������
	int* tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(arr, 0, n - 1, tmp);
	free(tmp);
}
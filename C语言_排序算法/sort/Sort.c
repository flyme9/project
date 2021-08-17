#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
#include"Stack.h"
//交换
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//打印
void PrintArray(int* arr, int n)
{
	//打印升序
	for (int i = 0; i <n; i++)
	//打印降序
	//for(int i=n-1;i>=0;i--)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
// 插入排序
void InsertSort(int* arr, int n)
{	
	//[0, end]有序  end+1位置的值插入[0, end]，让[0, end+1]有序
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		//指向第i个元素
		int tmp = arr[end + 1];
		//保存end后一个元素的值
		while (end >= 0)
		{
			if (arr[end] > tmp)
			{//end指向元素大于tmp，则将end指向的元素往后挪
				arr[end + 1] = arr[end];
				end--;
			}
			else
				break;
			//如果end指向的元素小于等于tmp，则不需要进行挪动元素
		}
		//end为--后的返回值
		//找到位置后，插入在end指向元素后一个位置
		arr[end + 1] = tmp;
	}
}
// 希尔排序
void ShellSort(int* arr, int n)
{
	int gap=n;//分组长度
	while (gap > 1)
	{
		gap /= 2;
		//最后为1
		gap = gap / 3 + 1;
		//最后为0或者为1，为0时排序未完成，所以+1
		//gap==1时，为直接插入排序
		//gap>1时，为预排序

		//
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			//指向第i个元素
			int tmp = arr[end + gap];
			//保存这组gap步长的元素
			while (end >= 0)
			{
				if (arr[end] > arr[end + gap])
				{	//挪动元素
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
					break;
			}
			//将tmp给end+gap位置
			arr[end + gap] = tmp;
		}
	}
}
// 选择排序
void SelectSort(int* arr, int n)
{
	//for (int i = 0; i < n-1; i++)
	//{
	//	int min = i;
	//	for (int j = i+1; j < n; j++)
	//	{
	//		if (arr[min] > arr[j])
	//		{	//如果min大于j位置的值，进行交换
	//			Swap(&arr[min], &arr[j]);
	//		}
	//	}
	//}
	//优化，双指针
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
// 堆排序
void AdjustDwon(int* arr, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;//从左孩子开始
	while (child < n)
	{
		//if (child + 1 < n&&arr[child + 1] < arr[child])
		//{
		//	child++;
		//}
		//if (arr[child] < arr[parent])
		//{
		//	//如果孩子比父亲小，交换位置
		//	Swap(&arr[child], &arr[parent]);
		//	parent = child;//将孩子指向的元素给父亲
		//	child = parent * 2 + 1;//下一棵子树的左孩子
		//}
		//else
		//{
		//	break;
		//}

		//建大堆,选出左右孩子中大的那个
		if (child + 1 < n&&arr[child + 1] > arr[child])
			child++;
		if (arr[child] > arr[parent])
		{
			//如果孩子比父亲大，交换位置
			Swap(&arr[child], &arr[parent]);
			parent = child;//将孩子指向的元素给父亲
			child = parent * 2 + 1;//下一棵子树的左孩子
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* arr, int n)
{
	//建堆
	//从最后一颗子树的非叶节点的子树进行调整
	for (int i = (n - 2) / 2; i >= 0; i--)
		AdjustDwon(arr, n, i);
	//排升序,建大堆
	int end = n - 1;
	while (end > 0)
	{
		//将最大的元素放到最后
		Swap(&arr[0], &arr[end]);
		AdjustDwon(arr, end, 0);
		end--;
	}
}
// 冒泡排序
void BubbleSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)//进行n-1趟冒泡排序
	{
		int falg = 0;
		for (int j = 0; j < n - 1 - i; j++)//每趟进行n-1-i次比较
		{
			if (arr[j] > arr[j+1])
				//如果前一个比后一个大，进行交换
				Swap(&arr[j], &arr[j+1]);
			falg = 1;
		}
		if (falg == 0)
			break;
	}
}
// 快速排序
//三数取中
int GetMidIndex(int* arr, int left, int right)
{
	int mid = (left + right) >> 1;
	if (arr[left] < arr[mid])
	{
		//中间值大于左边，大于右边
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
//挖坑法
int PartSort1(int* arr, int left, int right)
{
	//取中间值
	int index = GetMidIndex(arr, left, right);
	//交换左值和中间值位置
	Swap(&arr[left], &arr[right]);
	int begin = left, end = right;
	int pivot = begin;
	int key = arr[begin];
	while (begin < end)
	{
		// 右边找小，放到左边
		while (begin < end && arr[end] >= key)
			--end;
		// 小的放到左边的坑里，自己形成新的坑位
		arr[pivot] = arr[end];
		pivot = end;
		// 左边找大
		while (begin < end && arr[begin] <= key)
			++begin;
		// 大的放到左边的坑里，自己形成新的坑位
		arr[pivot] = arr[begin];
		pivot = begin;
	}
	pivot = begin;
	arr[pivot] = key;
	return pivot;//返回坑的位置
}
int PartSort2(int* arr, int left, int right)
{
	int index = GetMidIndex(arr, left, right);
	Swap(&arr[left], &arr[index]);
	int begin = left, end = right;
	int key = begin;
	while (begin < end)
	{
		//右边找小
		while (begin < end&&arr[end] >= arr[key])
			end--;
		//左边找大
		while (begin < end&&arr[begin] <= arr[key])
			begin++;
		//交换
		Swap(&arr[begin], &arr[end]);
	}
	//key和begin交换
	Swap(&arr[begin], &arr[key]);
	return begin;
}
//前后指针法
int PartSort3(int* arr, int left, int right)
{
	int index = GetMidIndex(arr, left, right);
	Swap(&arr[left], &arr[index]);
	int key = left;
	int prev = left, cur = left + 1;
	while (cur <= right)
	{
		//小的换到左边，++prev!=cur防止prev和cur指向同一个位置也进行交换
		if (arr[cur] < arr[key]&&++prev!=cur)
		{
			//小于，交换
			Swap(&arr[prev], &arr[cur]);
		}
		//不小于，cur继续走
		cur++;
	}
	//将key和prev交换
	Swap(&arr[key], &arr[prev]);
	return prev;
}
void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
		return;
	int keyIndex = PartSort3(arr, left, right);
	//左区间[left,pivot-1]
	//坑piovt
	//右区间[pivot+1,right]
	// 小区间
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
		int pivot = arr[left];//保存基准数
		int leftCur = left+1;
		int rightCur = right;
		while (leftCur < rightCur)
		{
			if (arr[leftCur] > pivot)
			{
				//左边放比基准数小的数，右边放比基准数大的数
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
// 归并排序
void _MergeSort(int* arr, int left, int right, int* tmp)
{
	if (left >= right)
		return;
	//计算出中间指针
	//分解
	int mid = (left + right) >> 1;
	_MergeSort(arr, left, mid, tmp);
	_MergeSort(arr, mid + 1, right, tmp);
	//归并
	int begin1 = left, end1 = mid;//左区间
	int begin2 = mid + 1, end2 = right;//右区间
	int index = left;
	//其中一个结束就结束
	while (begin1 <= end1&&begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
			tmp[index++] = arr[begin1++];
		else
			tmp[index++] = arr[begin2++];
	}
	//begin1数组有元素
	while (begin1 <= end1)
		tmp[index++] = arr[begin1++];
	//begin2数组有元素
	while (begin2 <= end2)
		tmp[index++] = arr[begin2++];
	//有序以后，拷贝会原数组
	for (int i = 0; i <= right; i++)
		arr[i] = tmp[i];
}
void MergeSort(int* arr, int n)
{
	//左半区间有序
	//右半区间有序
	//归并，依次对比，取小的放到临时数组中
	//临时数组有序，拷贝回数组
	int* tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(arr, 0, n - 1, tmp);
	free(tmp);
}
#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"
void TestOP()
{
	srand((unsigned int)time(0));
	const int N = 1000000;
	int* a1 = (int*)malloc(sizeof(int)*N);
	int* a2 = (int*)malloc(sizeof(int)*N);
	int* a3 = (int*)malloc(sizeof(int)*N);
	int* a4 = (int*)malloc(sizeof(int)*N);
	int* a5 = (int*)malloc(sizeof(int)*N);
	int* a6 = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}
	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	MergeSort(a6, N);
	int end6 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}
void TestInsertSort()
{
	int arr[] = { 3,2,1,6,5,4,9,8,7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, size);
	PrintArray(arr, size);
}
void TestShellSort()
{
	int arr[] = { 3,2,1,6,5,4,9,8,7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, size);
	PrintArray(arr, size);
}
void TestHeapSort()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, size);
	PrintArray(arr, size);
}
void TestSelectSort()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, size);
	PrintArray(arr, size);
}
void TestBubbleSort()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, size);
	PrintArray(arr, size);
}
void TestQuickSort()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0])-1;
	QuickSort(arr, left,right);
	PrintArray(arr, right+1);
}
void TestMergeSort()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	MergeSort(arr, size);
	PrintArray(arr, size);
}
void TestQuickSortNonR()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	QuickSortNonR(arr, size);
	PrintArray(arr, size);
}
int main()
{
	TestInsertSort();
	TestShellSort();
	TestHeapSort();
	TestSelectSort();
	TestBubbleSort();
	TestQuickSort();
	TestMergeSort();
	TestQuickSortNonR();
	TestOP();
	return 0;
}
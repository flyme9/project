#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//??ӡ
void PrintArray(int* arr, int n);
// ????????
void InsertSort(int* arr, int n);
// ϣ??????
void ShellSort(int* arr, int n);
// ѡ??????
void SelectSort(int* arr, int n);
// ??????
void AdjustDwon(int* arr, int n, int root);
void HeapSort(int* arr, int n);
// ð??????
void BubbleSort(int* arr, int n);
// ????????
void QuickSort(int* arr, int left, int right);
void QuickSort2(int* arr, int left, int right);
void QuickSortNonR(int* a, int n);
// ?鲢????
void MergeSort(int* arr, int n);
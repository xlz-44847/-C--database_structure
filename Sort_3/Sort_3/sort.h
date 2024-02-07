#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"


// 冒泡排序
void BubbleSort(int* a, int n);

// 快速排序递归实现
void QuickSort1(int* a, int left, int right);
void QuickSort2(int* a, int left, int right);
void QuickSort3(int* a, int left, int right);

// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right);
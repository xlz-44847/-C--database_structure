#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<time.h>

#include"Stack.h"

void InsertSort(int* a, int n);
void BubbleSort(int* a, int n);
void ShellSort(int* a, int n);
void SelectSort(int* a, int n);
void HeapSort(int* a, int n);
void QuickSort_Hoare(int* a, int begin, int end);
void QuickSort_Hoare_Opt(int* a, int begin, int end);
void QuickSort(int* a, int begin, int end);
void QuickSortNonR(int* a, int begin, int end);
void MergeSort(int* a, int n);
void MergeSortNonR(int* a, int n);
void CountSort(int* a, int n);
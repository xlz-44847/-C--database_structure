#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"


// ð������
void BubbleSort(int* a, int n);

// ��������ݹ�ʵ��
void QuickSort1(int* a, int left, int right);
void QuickSort2(int* a, int left, int right);
void QuickSort3(int* a, int left, int right);

// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right);
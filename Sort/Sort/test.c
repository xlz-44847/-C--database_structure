#include"sort.h"

int main()
{
	int a[] = { 2,6,5,8,4,1,3,7,9,0 };
	int b[] = { 2,0,2,4,9,5,1,0,0,3,4,-5,-1,6,-3,-3,-1,-1,6,5,8,4,1,3,7,9,0 };
	InsertSort(a, sizeof(a) / sizeof(a[0]));
	//BubbleSort(a, sizeof(a) / sizeof(a[0]));
	//ShellSort(a, sizeof(a) / sizeof(a[0]));
	//SelectSort(a, sizeof(a) / sizeof(a[0]));
	//HeapSort(a, sizeof(a) / sizeof(a[0]));
	//QuickSort_Hoare(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	//QuickSort_Hoare_Opt(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	//QuickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	//QuickSortNonR(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	//MergeSort(a, sizeof(a) / sizeof(a[0]));
	//MergeSortNonR(a, sizeof(a) / sizeof(a[0]));
	CountSort(b, sizeof(b) / sizeof(b[0]));
	return 0;
 }
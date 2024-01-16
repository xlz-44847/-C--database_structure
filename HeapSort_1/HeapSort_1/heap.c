#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void swap(int* pa, int* pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

void AdjustDownMax(int* a, int parent, int n)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			swap(&a[parent], &a[child]);
			parent = child;
			child = child * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	//n-1是最后一个结点的下标
	//（（n-1）-1）/2是最后一个结点的父结点
	//向下调整建堆是从最后一个分支结点开始向前依次向下调整
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDownMax(a, i, n);
	}
	//向下调整出数据
	for (int i = n - 1; i >= 0; i--)
	{
		swap(&a[0], &a[i]);
		AdjustDownMax(a, 0, i);
	}
}

void Print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 2,3,6,8,7,4,1,9,5,0 };
	Print(arr, sizeof(arr) / sizeof(arr[0]));
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	Print(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}
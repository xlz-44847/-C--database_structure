#include"sort.h"

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// 选择排序
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		//[begin,end]选最大和最小
		int mini = begin, maxi = end;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		swap(&a[mini], &a[begin]);
		if (maxi == begin)
		{
			maxi = mini;
		}
		swap(&a[maxi], &a[end]);
		begin++;
		end--;
	}
}


void AdjustDownMax(int* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void AdjustDownMin(int* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] < a[child])
		{
			child++;
		}
		if (a[parent] > a[child])
		{
			swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// 堆排序
// 升序——建大堆
void HeapSort1(int* a, int n)
{
	//向下调整建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDownMax(a, n, i);
	}
	//换位取数，向下调整
	for (int i = n - 1; i > 0; i--)
	{
		swap(&a[0], &a[i]);
		AdjustDownMax(a, i, 0);
	}
}
// 降序——建小堆
void HeapSort2(int* a, int n)
{
	//向下调整建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDownMin(a, n, i);
	}
	//换位取数，向下调整
	for (int i = n - 1; i > 0; i--)
	{
		swap(&a[0], &a[i]);
		AdjustDownMin(a, i, 0);
	}
}
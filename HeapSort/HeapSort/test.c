#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void AdjustUpMax(int* arr, int size)
{
	int child = size - 1;
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (arr[child] > arr[parent])
		{
			swap(&arr[child], &arr[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void AdjustDownMax(int* arr, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && arr[child] < arr[child + 1])
		{
			child++;
		}
		if (arr[child] > arr[parent])
		{
			swap(&arr[child], &arr[parent]);
			parent = child;
			child = child * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void AdjustUpMin(int* arr, int size)
{
	int child = size - 1;
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (arr[child] < arr[parent])
		{
			swap(&arr[child], &arr[parent]);
			child = parent;
			parent = (parent - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void AdjustDownMin(int* arr, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && arr[child] > arr[child + 1])
		{
			child++;
		}
		if (arr[child] < arr[parent])
		{
			swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}

	}
}

int main()
{
	int arr[10] = { 8,5,2,1,6,9,4,3,0,7 };
	//升序——建大堆——建堆==插入数据==向上调整 -->O(N*logN)
	/*for (int i = 0; i < 10; i++)
	{
		AdjustUpMax(arr, i + 1);
	}*/
	//向下调整建堆 -->O(N)
	for (int i = (10 - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDownMax(arr, 10, i);
	}


	//升序——大堆出数据——删除数据==向下调整
	for (int i = 10; i > 0; i--)
	{
		swap(&arr[0], &arr[i - 1]);
		AdjustDownMax(arr, i - 1, 0);
	}
	//top-k问题
	//建立k个元素的小堆
	int k = 5;
	int* heap = (int*)malloc(sizeof(int) * k);
	if (heap == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	for (int i = 0; i < 10; i++)
	{
		if (i < k)
		{
			heap[i] = arr[i];
			AdjustUpMin(heap, i);
		}
		else
		{
			if (arr[i] > heap[0])
			{
				heap[0] = arr[i];
				AdjustDownMin(heap, k, 0);
			}
		}
	}
	free(heap);
	heap = NULL;
	return 0;
}
#include"sort.h"

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//归并排序
void _MergeSort(int* a, int* tmp, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int mid = (begin + end) / 2;
	_MergeSort(a, tmp, begin, mid);
	_MergeSort(a, tmp, mid + 1, end);
	int cur = begin;
	int head1 = begin, head2 = mid + 1;
	while (head1 <= mid && head2 <= end)
	{
		if (a[head1] < a[head2])
		{
			tmp[cur++] = a[head1++];
		}
		else
		{
			tmp[cur++] = a[head2++];
		}
	}
	while (head1 <= mid)
	{
		tmp[cur++] = a[head1++];
	}
	while (head2 <= end)
	{
		tmp[cur++] = a[head2++];
	}
	for (int i = begin; i <= end; i++)
	{
		a[i] = tmp[i];
	}
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}
	_MergeSort(a, tmp, 0, n - 1);
	free(tmp);
}

//非递归
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, begin2 = i + gap;
			int end1 = i + gap - 1, end2 = i + 2 * gap - 1;
			//begin1恒<n
			if (end1 >= n || begin2 >= n)//2组为空，无需排序
			{
				break;
			}
			if (end2 >= n)//2组不全，调整边界
			{
				end2 = n - 1;
			}
			int head1 = begin1, head2 = begin2;
			int cur = begin1;
			while (head1 <= end1 && head2 <= end2)
			{
				if (a[head1] < a[head2])
				{
					tmp[cur++] = a[head1++];
				}
				else
				{
					tmp[cur++] = a[head2++];
				}
			}
			while (head1 <= end1)
			{
				tmp[cur++] = a[head1++];
			}
			while (head2 <= end2)
			{
				tmp[cur++] = a[head2++];
			}
			for (int i = begin1; i <= end2; i++)
			{
				a[i] = tmp[i];
			}
		}
		gap *= 2;
	}
	free(tmp);
}
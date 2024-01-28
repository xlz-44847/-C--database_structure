#include"sort.h"

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// ��������
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		//[0,end]������Ҫ��end+1��������������
		int end = i;
		int cmp = a[end + 1];
		while (end >= 0)
		{
			if (cmp < a[end])
			{
				a[end + 1] = a[end];
			}
			else
			{
				break;
			}
			end--;
		}
		a[end + 1] = cmp;
	}
}

// ϣ������
void ShellSort1(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < gap; i++)
		{
			for (int j = i; j < n - gap; j += gap)
			{
				int end = j;
				int cmp = a[j + gap];
				while (end >= 0)
				{
					if (cmp < a[end])
					{
						a[end + gap] = a[end];
						end -= gap;
					}
					else
					{
						break;
					}
				}
				a[end + gap] = cmp;
			}
		}
	}
}

void ShellSort2(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int cmp = a[i + gap];
			while (end >= 0)
			{
				if (cmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
				a[end + gap] = cmp;
			}
		}
	}
}
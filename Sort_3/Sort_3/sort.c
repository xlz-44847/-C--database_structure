#include"sort.h"

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// 冒泡排序
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int flag = 1;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				flag = 0;
				swap(&a[j], &a[j + 1]);
			}
		}
		if (flag)
		{
			break;
		}
	}
}

// 快速排序递归实现
// 三数取中
int GetMid(int* a, int left, int right)
{
	int midi = (left + right) / 2;
	if (a[left] > a[right])
	{
		if (a[left] < a[midi])
		{
			return midi;
		}
		else
		{
			if (a[midi] > a[right])
			{
				return midi;
			}
			else
			{
				return right;
			}
		}
	}
	else
	{
		if (a[right] < a[midi])
		{
			return right;
		}
		else
		{
			if (a[midi] > a[left])
			{
				return midi;
			}
			else
			{
				return left;
			}
		}
	}
}
// 快速排序hoare版本
int PartSort1(int* a, int left, int right)
{
	int midi = GetMid(a, left, right);
	swap(&a[midi], &a[left]);
	int keyi = left;
	while (right > left)
	{
		while (right > left && a[right] >= a[keyi])
		{
			right--;
		}
		while (right > left && a[left] <= a[keyi])
		{
			left++;
		}
		swap(&a[left], &a[right]);
	}
	swap(&a[left], &a[keyi]);
	return left;
}
// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	int keyi = GetMid(a, left, right);
	swap(&a[left], &a[keyi]);
	int hole = left;
	int key = a[left];
	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;
		while (left < right && a[left] <= key)
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}
// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{
	int midi = GetMid(a, left, right);
	swap(&a[midi], &a[left]);
	int keyi = left;
	int front = left + 1, behind = left;
	while (front <= right)
	{
		if (a[front] < a[keyi])
		{
			behind++;
			swap(&a[behind], &a[front]);
		}
		front++;
	}
	swap(&a[behind], &a[keyi]);
	return behind;
}

void QuickSort1(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int mid = PartSort1(a, left, right);
	//[left,mid-1] mid [mid+1,right]
	QuickSort1(a, left, mid - 1);
	QuickSort1(a, mid + 1, right);
}
void QuickSort2(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int mid = PartSort2(a, left, right);
	//[left,mid-1] mid [mid+1,right]
	QuickSort2(a, left, mid - 1);
	QuickSort2(a, mid + 1, right);
}
void QuickSort3(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int mid = PartSort3(a, left, right);
	//[left,mid-1] mid [mid+1,right]
	QuickSort3(a, left, mid - 1);
	QuickSort3(a, mid + 1, right);
}

// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right)
{
	ST s;
	STInit(&s);
	//存：先右后左  取：先左后右
	STPush(&s, right);
	STPush(&s, left);
	while (!STEmpty(&s))
	{
		int begin = STTop(&s);
		STPop(&s);
		int end = STTop(&s);
		STPop(&s);
		int mid = PartSort1(a, begin, end);
		if (mid - 1 > begin)
		{
			STPush(&s, mid - 1);
			STPush(&s, begin);
		}
		if (mid + 1 < end)
		{
			STPush(&s, end);
			STPush(&s, mid + 1);
		}
	}
	STDestroy(&s);
}
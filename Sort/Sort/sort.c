#include"sort.h"

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		//[0,end]已经有序，将end+1插入有序数组内
		int end = i;
		int	tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n; j++)
	{
		bool flag = true;
		for (int i = 0; i < n - 1 - j; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(&a[i], &a[i + 1]);
				flag = false;
			}
		}
		if (flag)
		{
			break;
		}
	}
}

//希尔排序对于不同于处理组统一处理的方案
void ShellSort(int* a, int n)
{
	//预排序
	
	//int gap = 3;
	int gap = n;
	//gap>1时是预排序
	//gap==1时是直接插入排序
	while (gap > 1)
	{
		//gap在循环中应该递减为1
		//gap = gap / 2;  //gap/2最后都可以到达1
		gap = gap / 3 + 1; //对gap除以3，商可能是任意整数并且一定比被除数小，即gap是递减的
						   //对于gap/3循环，gap是有可能不经过1而直接到达0的，所以需要加1确保gap一定可以到达1
			for (int i = 0; i < n - gap; i++)
			{
				int end = i;//前end个元素已经有序
				int tmp = a[end + gap]; //待插入数据
				while (end >= 0)
				{
					if (tmp < a[end])
					{
						a[end + gap] = a[end];
						end -= gap;
					}
					else
					{
						break;
					}
				}
				a[end + gap] = tmp;
			}
	}
}

//希尔排序对于不同于处理组分组处理的方案
//void ShellSort(int* a, int n)
//{
//	//预排序
//
//	//int gap = 3;
//	int gap = n;
//	//gap>1时是预排序
//	//gap==1时是直接插入排序
//	while (gap > 1)
//	{
//		//gap在循环中应该递减为1
//		//gap = gap / 2;  //gap/2最后都可以到达1
//		gap = gap / 3 + 1; //对gap除以3，商可能是任意整数并且一定比被除数小，即gap是递减的
//		//对于gap/3循环，gap是有可能不经过1而直接到达0的，所以需要加1确保gap一定可以到达1
//		for (int j = 0; j < gap; j++)
//		{
//			for (int i = j; i < n - gap; i += gap)//i作为坐标预处理数组元素下标
//			{
//				int end = i;//前end个元素已经有序
//				int tmp = a[end + gap]; //待插入数据
//				while (end >= 0)
//				{
//					if (tmp < a[end])
//					{
//						a[end + gap] = a[end];
//						end -= gap;
//					}
//					else
//					{
//						break;
//					}
//				}
//				a[end + gap] = tmp;
//			}
//		}
//	}
//}

void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int maxi = end, mini = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
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
	while (child<size)
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

void HeapSort(int* a, int n)
{
	//排升序，建大堆，采用向下调整建堆的方法
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDownMax(a, n, i);
	}
	//出堆并向下调整
	for (int i = n - 1; i > 0; i--)
	{
		swap(&a[i], &a[0]);
		AdjustDownMax(a, i, 0);
	}
}

//快速排序（hoare版本）
void QuickSort_Hoare(int* a, int begin, int end)
{
	//需要对[begin,end]进行排序
	if (begin >= end)
	{
		return;
	}
	int keyi = begin; //如果设置key=a[begin]，在后续交换时穿参需要变化，不可以是&key
	int left = begin, right = end; //如果left从begin+1开始，对于如1 2 3 4 5序列，途中left不移动，但是keyi和left的交换依旧会发生
	while (left < right)
	{
		while (left < right && a[right] >= a[keyi]) //判断条件需要left<right，防止越界访问
		{
			right--;
		}
		while (left < right && a[left] <= a[keyi]) //判断时需要<=或>=，防止对于如6 1 2 6 5 6 9 8有重复数字序列陷入死循环
		{
			left++;
		}
		swap(&a[left], &a[right]);
	}
	swap(&a[left], &a[keyi]);
	keyi = left;
	//[begin,keyi-1] keyi [keyi+1,end]
	QuickSort_Hoare(a, begin, keyi - 1);
	QuickSort_Hoare(a, keyi + 1, end);
}

//快速排序--优化方案
int GetMidi(int* a, int begin, int end)
{
	int midi = (begin + end) / 2;
	//取begin，end，midi三者的中位数
	return a[begin] > a[end] ? (a[end] > a[midi] ? end : (a[begin] > a[midi] ? midi : begin)) : a[begin] > a[midi] ? begin : (a[end] > a[midi] ? midi : end);
}

void QuickSort_Hoare_Opt(int* a, int begin, int end)
{
	//需要对[begin,end]进行排序
	if (begin >= end)
	{
		return;
	}

//快速排序--优化1--小区间优化
//小区间优化：当所处理数据长度足够小时，使用其他更合适的排序方式处理，因为快排实际上类似于二叉树，小区间优化可以对树的最后几层进行剪枝，大大减小递归开销（因为编译器对递归优化很好，所以效果不明显）
	//*******************************************
	if (end - begin + 1 <= 3)
	{
		InsertSort(a + begin, end - begin + 1);
		return;
	}
	//*******************************************
	else
	{
//快速排序--优化2--三数取中
//三数取中：区间第一个，最后一个，中间三个位置数字相比，将三者的中位数作为key，这样使得每一次的递归分治尽量均分，提高处理效率
		//*******************************************
		int midi = GetMidi(a, begin, end);
		swap(&a[begin], &a[midi]);
		int keyi = begin;
		//*******************************************
		int left = begin, right = end;
		while (left < right)
		{
			while (left < right && a[right] >= a[keyi])
			{
				right--;
			}
			while (left < right && a[left] <= a[keyi])
			{
				left++;
			}
			swap(&a[left], &a[right]);
		}
		swap(&a[left], &a[keyi]);
		keyi = left;
		QuickSort_Hoare_Opt(a, begin, keyi - 1);
		QuickSort_Hoare_Opt(a, keyi + 1, end);
	}
}

//快速排序常见三种形式
//1.Hoare版本
//right找小，left找大，相遇后放入key
int Sort1_Hoare(int* a, int begin, int end)
{
	int midi = GetMidi(a, begin, end);
	swap(&a[begin], &a[midi]);
	int keyi = begin;

	int left = begin, right = end;
	while (left < right)
	{
		while (left < right && a[right] >= a[keyi])
		{
			right--;
		}
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}
		swap(&a[left], &a[right]);
	}
	swap(&a[left], &a[keyi]);
	keyi = left;
	return keyi;
}

//2.挖坑法
//right找小，left找大，每次找到后即刻将key填入
int PartSort2(int* a, int left, int right)
{
	int keyi = GetMidi(a, left, right);
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
//此方法虽然也对，但没有很好的复刻挖坑法
//int Sort2_Hole(int* a, int begin, int end)
//{
//	int midi = GetMidi(a, begin, end);
//	swap(&a[begin], &a[midi]);
//	int key = a[begin];
//
//	int holei = begin;
//	int left = begin, right = end;
//	while (left < right)
//	{
//		while (left < right && a[right] >= key)
//		{
//			right--;
//		}
//		swap(&a[holei], &a[right]);
//		holei = right;
//		while (left < right && a[left] <= key)
//		{
//			left++;
//		}
//		swap(&a[holei], &a[left]);
//		holei = left;
//	}
//	return holei;
//}

//3.前后指针法
//利用cur指针遍历整个数组，cur指向正在辨别的元素，prev指向左侧区间边界（也是key应该处在的位置），两个指针之间(prev,cur)是右侧分治的元素
//所以当cur遇到小于key的数据，需要将其放在prev的下一个位置，再挪动cur；遇到大于key的数据，则不必移动prev，只需要挪动cur即可
int Sort3_Pointer(int* a, int begin, int end)
{
	int midi = GetMidi(a, begin, end);
	swap(&a[midi], &a[begin]);

	int key = a[begin];
	int prev = begin, cur = begin + 1;
	while (cur <= end)
	{
		//if (a[cur] < key)
		//{
		//	prev++;
		//	swap(&a[prev], &a[cur]);
		//}
		if (a[cur] < key && ++prev != cur)
		{
			swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	swap(&a[prev], &a[begin]);
	return prev;
}

//快速排序递归版
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	//int keyi = Sort1_Hoare(a, begin, end);
	//int keyi = Sort2_Hole(a, begin, end);
	int keyi = Sort3_Pointer(a, begin, end);
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}

//快速排序非递归版
void QuickSortNonR(int* a, int begin, int end)
{
	ST s;
	STInit(&s);

	//将待处理区间左右端点存入栈中，以两个为一组。存：先右后左；取：先左后右
	STPush(&s, end);
	STPush(&s, begin);
	while (!STEmpty(&s))
	{
		int left = STTop(&s);
		STPop(&s);
		int right = STTop(&s);
		STPop(&s);
		if (left < right)
		{
			int keyi = Sort3_Pointer(a, left, right);
			STPush(&s, right);
			STPush(&s, keyi + 1);
			STPush(&s, keyi - 1);
			STPush(&s, left);
		}
	}

	STDestroy(&s);
}

//归并排序
void _MergeSort(int* a, int* tmp, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}

	int mid = (end + begin) / 2;

	_MergeSort(a, tmp, begin, mid);
	_MergeSort(a, tmp, mid + 1, end);

	int head1 = begin;
	int head2 = mid + 1;
	int cur = begin;
	while (head1 <= mid && head2 <= end)
	{
		if (a[head1] > a[head2])
		{
			tmp[cur++] = a[head2++];
		}
		else
		{
			tmp[cur++] = a[head1++];
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
			int begin1 = i, end1 = i + gap - 1;//归并中第一个区间的范围
			int begin2 = i + gap, end2 = i + 2 * gap - 1;//归并中第二个区间的范围
			int head1 = begin1, head2 = begin2;
			int cur = begin1;
			if (end1 >= n || begin2 >= n)//数据只存在于第一个区间中，而第二个区间没有数据，这时无需归并（因为只有一组数据已然有序）
			{
				break;
			}
			if (end2 >= n)//第二个区间数据不满，此时需要对第二个区间进行调整，然后再归并
			{
				end2 = n - 1;//这种情况只会在最后一组出现，所以直接赋值end2为序列最后一个元素下标即可
			}
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

void CountSort(int* a, int n)
{
	//找到偏移量
	int min = a[0], max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
		if (a[i] > max)
		{
			max = a[i];
		}
	}

	int range = max - min + 1;

	int* cou = (int*)calloc(range, sizeof(int));
	if (cou == NULL)
	{
		perror("calloc fail");
		return;
	}

	//计数
	for (int i = 0; i < n; i++)
	{
		cou[a[i] - min]++;
	}
	//排序
	int k = 0;
	for (int i = 0; i < range; i++)
	{
		for (int j = 0; j < cou[i]; j++)
		{
			a[k++] = i + min;
		}
	}
}
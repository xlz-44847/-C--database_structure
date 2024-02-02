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
		//[0,end]�Ѿ����򣬽�end+1��������������
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

//ϣ��������ڲ�ͬ�ڴ�����ͳһ����ķ���
void ShellSort(int* a, int n)
{
	//Ԥ����
	
	//int gap = 3;
	int gap = n;
	//gap>1ʱ��Ԥ����
	//gap==1ʱ��ֱ�Ӳ�������
	while (gap > 1)
	{
		//gap��ѭ����Ӧ�õݼ�Ϊ1
		//gap = gap / 2;  //gap/2��󶼿��Ե���1
		gap = gap / 3 + 1; //��gap����3���̿�����������������һ���ȱ�����С����gap�ǵݼ���
						   //����gap/3ѭ����gap���п��ܲ�����1��ֱ�ӵ���0�ģ�������Ҫ��1ȷ��gapһ�����Ե���1
			for (int i = 0; i < n - gap; i++)
			{
				int end = i;//ǰend��Ԫ���Ѿ�����
				int tmp = a[end + gap]; //����������
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

//ϣ��������ڲ�ͬ�ڴ�������鴦��ķ���
//void ShellSort(int* a, int n)
//{
//	//Ԥ����
//
//	//int gap = 3;
//	int gap = n;
//	//gap>1ʱ��Ԥ����
//	//gap==1ʱ��ֱ�Ӳ�������
//	while (gap > 1)
//	{
//		//gap��ѭ����Ӧ�õݼ�Ϊ1
//		//gap = gap / 2;  //gap/2��󶼿��Ե���1
//		gap = gap / 3 + 1; //��gap����3���̿�����������������һ���ȱ�����С����gap�ǵݼ���
//		//����gap/3ѭ����gap���п��ܲ�����1��ֱ�ӵ���0�ģ�������Ҫ��1ȷ��gapһ�����Ե���1
//		for (int j = 0; j < gap; j++)
//		{
//			for (int i = j; i < n - gap; i += gap)//i��Ϊ����Ԥ��������Ԫ���±�
//			{
//				int end = i;//ǰend��Ԫ���Ѿ�����
//				int tmp = a[end + gap]; //����������
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
	//�����򣬽���ѣ��������µ������ѵķ���
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDownMax(a, n, i);
	}
	//���Ѳ����µ���
	for (int i = n - 1; i > 0; i--)
	{
		swap(&a[i], &a[0]);
		AdjustDownMax(a, i, 0);
	}
}

//��������hoare�汾��
void QuickSort_Hoare(int* a, int begin, int end)
{
	//��Ҫ��[begin,end]��������
	if (begin >= end)
	{
		return;
	}
	int keyi = begin; //�������key=a[begin]���ں�������ʱ������Ҫ�仯����������&key
	int left = begin, right = end; //���left��begin+1��ʼ��������1 2 3 4 5���У�;��left���ƶ�������keyi��left�Ľ������ɻᷢ��
	while (left < right)
	{
		while (left < right && a[right] >= a[keyi]) //�ж�������Ҫleft<right����ֹԽ�����
		{
			right--;
		}
		while (left < right && a[left] <= a[keyi]) //�ж�ʱ��Ҫ<=��>=����ֹ������6 1 2 6 5 6 9 8���ظ���������������ѭ��
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

//��������--�Ż�����
int GetMidi(int* a, int begin, int end)
{
	int midi = (begin + end) / 2;
	//ȡbegin��end��midi���ߵ���λ��
	return a[begin] > a[end] ? (a[end] > a[midi] ? end : (a[begin] > a[midi] ? midi : begin)) : a[begin] > a[midi] ? begin : (a[end] > a[midi] ? midi : end);
}

void QuickSort_Hoare_Opt(int* a, int begin, int end)
{
	//��Ҫ��[begin,end]��������
	if (begin >= end)
	{
		return;
	}

//��������--�Ż�1--С�����Ż�
//С�����Ż��������������ݳ����㹻Сʱ��ʹ�����������ʵ�����ʽ������Ϊ����ʵ���������ڶ�������С�����Ż����Զ�������󼸲���м�֦������С�ݹ鿪������Ϊ�������Եݹ��Ż��ܺã�����Ч�������ԣ�
	//*******************************************
	if (end - begin + 1 <= 3)
	{
		InsertSort(a + begin, end - begin + 1);
		return;
	}
	//*******************************************
	else
	{
//��������--�Ż�2--����ȡ��
//����ȡ�У������һ�������һ�����м�����λ��������ȣ������ߵ���λ����Ϊkey������ʹ��ÿһ�εĵݹ���ξ������֣���ߴ���Ч��
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

//�������򳣼�������ʽ
//1.Hoare�汾
//right��С��left�Ҵ����������key
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

//2.�ڿӷ�
//right��С��left�Ҵ�ÿ���ҵ��󼴿̽�key����
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
//�˷�����ȻҲ�ԣ���û�кܺõĸ����ڿӷ�
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

//3.ǰ��ָ�뷨
//����curָ������������飬curָ�����ڱ���Ԫ�أ�prevָ���������߽磨Ҳ��keyӦ�ô��ڵ�λ�ã�������ָ��֮��(prev,cur)���Ҳ���ε�Ԫ��
//���Ե�cur����С��key�����ݣ���Ҫ�������prev����һ��λ�ã���Ų��cur����������key�����ݣ��򲻱��ƶ�prev��ֻ��ҪŲ��cur����
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

//��������ݹ��
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

//��������ǵݹ��
void QuickSortNonR(int* a, int begin, int end)
{
	ST s;
	STInit(&s);

	//���������������Ҷ˵����ջ�У�������Ϊһ�顣�棺���Һ���ȡ���������
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

//�鲢����
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
			int begin1 = i, end1 = i + gap - 1;//�鲢�е�һ������ķ�Χ
			int begin2 = i + gap, end2 = i + 2 * gap - 1;//�鲢�еڶ�������ķ�Χ
			int head1 = begin1, head2 = begin2;
			int cur = begin1;
			if (end1 >= n || begin2 >= n)//����ֻ�����ڵ�һ�������У����ڶ�������û�����ݣ���ʱ����鲢����Ϊֻ��һ��������Ȼ����
			{
				break;
			}
			if (end2 >= n)//�ڶ����������ݲ�������ʱ��Ҫ�Եڶ���������е�����Ȼ���ٹ鲢
			{
				end2 = n - 1;//�������ֻ�������һ����֣�����ֱ�Ӹ�ֵend2Ϊ�������һ��Ԫ���±꼴��
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
	//�ҵ�ƫ����
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

	//����
	for (int i = 0; i < n; i++)
	{
		cou[a[i] - min]++;
	}
	//����
	int k = 0;
	for (int i = 0; i < range; i++)
	{
		for (int j = 0; j < cou[i]; j++)
		{
			a[k++] = i + min;
		}
	}
}
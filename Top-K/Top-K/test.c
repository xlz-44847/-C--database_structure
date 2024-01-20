#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>

void CreateNDate()
{
	// 造数据
	int n = 10000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 1000000;
		//if (i == 298)
		//{
		//	x += 1000000;
		//}
		//if (i == 28)
		//{
		//	x += 2000000;
		//}if (i == 1298)
		//{
		//	x += 3000000;
		//}if (i == 2298)
		//{
		//	x += 4000000;
		//}
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void AdjustUpMin(int* a, int child)
{
	int parent = (child - 1) / 2;
	while (parent>=0)
	{
		if (a[parent] > a[child])
		{
			swap(&a[parent], &a[child]);
			child = parent;
			parent = (parent - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void AdjustDownMin(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] < a[child])
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			swap(&a[child], &a[parent]);
			parent = child;
			child = child * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void PrintTopK(int k)
{
	FILE* fou = fopen("data.txt", "r");
	if (fou == NULL)
	{
		perror("fopen fail");
		return;
	}
	//建堆
	int* a = (int*)malloc(sizeof(int) * k);
	if (a == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	for (int i = 0; i < k; i++)
	{
		fscanf(fou, "%d", &a[i]);
		AdjustUpMin(a, i);
	}
	int num = 0;
	while (fscanf(fou, "%d", &num) != EOF)
	{
		if (num > a[0])
		{
			a[0] = num;
			AdjustDownMin(a, k, 0);
		}
	}
	//打印
	for (int i = 0; i < k; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	fclose(fou);
}

int main()
{
	CreateNDate();
	PrintTopK(10);
	return 0;
}
#include"sort.h"

void Print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void test1()
{
	int a[15] = { 5,9,11,2,14,6,0,12,3,1,13,7,4,8,10 };
	printf("�鲢���򣨵ݹ飩��\n����ǰ��");
	Print(a, sizeof(a) / sizeof(a[0]));
	MergeSort(a, sizeof(a) / sizeof(a[0]));
	printf("�����");
	Print(a, sizeof(a) / sizeof(a[0]));
}
void test2()
{
	int a[15] = { 5,9,11,2,14,6,0,12,3,1,13,7,4,8,10 };
	printf("�鲢���򣨷ǵݹ飩��\n����ǰ��");
	Print(a, sizeof(a) / sizeof(a[0]));
	MergeSortNonR(a, sizeof(a) / sizeof(a[0]));
	printf("�����");
	Print(a, sizeof(a) / sizeof(a[0]));
}

int main()
{
	test1();
	test2();
	return 0;
}
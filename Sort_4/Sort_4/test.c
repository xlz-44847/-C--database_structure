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
	printf("¹é²¢ÅÅÐò£¨µÝ¹é£©£º\nÅÅÐòÇ°£º");
	Print(a, sizeof(a) / sizeof(a[0]));
	MergeSort(a, sizeof(a) / sizeof(a[0]));
	printf("ÅÅÐòºó£º");
	Print(a, sizeof(a) / sizeof(a[0]));
}
void test2()
{
	int a[15] = { 5,9,11,2,14,6,0,12,3,1,13,7,4,8,10 };
	printf("¹é²¢ÅÅÐò£¨·ÇµÝ¹é£©£º\nÅÅÐòÇ°£º");
	Print(a, sizeof(a) / sizeof(a[0]));
	MergeSortNonR(a, sizeof(a) / sizeof(a[0]));
	printf("ÅÅÐòºó£º");
	Print(a, sizeof(a) / sizeof(a[0]));
}

int main()
{
	test1();
	test2();
	return 0;
}
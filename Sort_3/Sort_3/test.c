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
	printf("ð������\n����ǰ��");
	Print(a, sizeof(a) / sizeof(a[0]));
	BubbleSort(a, sizeof(a) / sizeof(a[0]));
	printf("�����");
	Print(a, sizeof(a) / sizeof(a[0]));
}
void test2()
{
	int a[15] = { 5,9,11,2,14,6,0,12,3,1,13,7,4,8,10 };
	printf("��������hoare����\n����ǰ��");
	Print(a, sizeof(a) / sizeof(a[0]));
	QuickSort1(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	printf("�����");
	Print(a, sizeof(a) / sizeof(a[0]));
}
void test3()
{
	int a[15] = { 5,9,11,2,14,6,0,12,3,1,13,7,4,8,10 };
	printf("���������ڿӷ�����\n����ǰ��");
	Print(a, sizeof(a) / sizeof(a[0]));
	QuickSort2(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	printf("�����");
	Print(a, sizeof(a) / sizeof(a[0]));
}
void test4()
{
	int a[15] = { 5,9,11,2,14,6,0,12,3,1,13,7,4,8,10 };
	printf("��������ǰ��ָ�룩��\n����ǰ��");
	Print(a, sizeof(a) / sizeof(a[0]));
	QuickSort2(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	printf("�����");
	Print(a, sizeof(a) / sizeof(a[0]));
}
void test5()
{
	int a[15] = { 5,9,11,2,14,6,0,12,3,1,13,7,4,8,10 };
	printf("�������򣨷ǵݹ飩��\n����ǰ��");
	Print(a, sizeof(a) / sizeof(a[0]));
	QuickSortNonR(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	printf("�����");
	Print(a, sizeof(a) / sizeof(a[0]));
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	return 0;
}
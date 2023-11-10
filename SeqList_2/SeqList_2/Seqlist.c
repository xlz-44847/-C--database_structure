#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void test1()
{
	SL sl;
	SeqListInit(&sl);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 0);
	SeqListPrint(&sl);

	SLPopFront(&sl);
	SeqListPrint(&sl);

	SLPopFront(&sl);
	SeqListPrint(&sl);

	SLPopFront(&sl);
	SeqListPrint(&sl);

	SLPopFront(&sl);
	SeqListPrint(&sl);

	SLPopFront(&sl);
	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}

void test2()
{
	SL sl;
	SeqListInit(&sl);
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 3);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 0);
	SeqListPrint(&sl);

	SLPopBack(&sl);
	SeqListPrint(&sl);

	SLPopBack(&sl);
	SeqListPrint(&sl);

	SLPopBack(&sl);
	SeqListPrint(&sl);

	SLPopBack(&sl);
	SeqListPrint(&sl);

	SLPopBack(&sl);
	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}

void test3()
{
	SL sl;
	SeqListInit(&sl);
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 3);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 0);
	SeqListPrint(&sl);

	SLInsert(&sl, 3, 77);
	SeqListPrint(&sl);

	SLInsert(&sl, 1, 99);
	SeqListPrint(&sl);

	SLErase(&sl,1);
	SeqListPrint(&sl);

	SLErase(&sl,3);
	SeqListPrint(&sl);

	int a = SLFind(&sl, 4);
	if (a == -1)
		printf("没找到\n");
	else
		printf("找到了，下标为：%d\n", a);

	SeqListDestroy(&sl);
}

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}
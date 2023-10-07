#define _CRT_SECURE_NO_WARNINGS 
#include"List.h"

void test1()
{
	LTNode* ps1 = ListInit();
	ListPushFront(ps1, 3);
	ListPushFront(ps1, 2);
	ListPushFront(ps1, 1);
	ListPrint(ps1);
	ListPushBack(ps1, 4);
	ListPushBack(ps1, 5);
	ListPushBack(ps1, 6);
	ListPrint(ps1);
	ListPopFront(ps1);
	ListPopFront(ps1);
	ListPrint(ps1);
	ListPopBack(ps1);
	ListPopBack(ps1);
	ListPrint(ps1);
	ListDestroy(ps1);
}
void test2()
{
	LTNode* ps1 = ListInit();
	ListPushFront(ps1, 3);
	ListPushFront(ps1, 2);
	ListPushFront(ps1, 1);
	ListPushBack(ps1, 4);
	ListPushBack(ps1, 5);
	ListPushBack(ps1, 6);
	ListPrint(ps1);
	ListInsert(ListFind(ps1, 1), 0);
	ListInsert(ListFind(ps1, 6), 48);
	ListPrint(ps1);
	ListErase(ListFind(ps1, 48));
	ListErase(ListFind(ps1, 7));
	ListPrint(ps1);
	ListDestroy(ps1);
}

int main()
{
	//test1();
	test2();
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 
#include"List.h"

void test1()
{
	LTNode* plist = LTInit();
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPushBack(plist, 5);
	LTPushFront(plist, 2);
	LTPushFront(plist, 1);
	LTPrint(plist);

	LTNode* p1 = LTFind(plist, 3);
	LTInsert(p1, 88);

	LTNode* p2 = LTFind(plist, 1);
	LTInsert(p2, 199);

	LTPrint(plist);

	LTPopBack(plist);
	LTPopBack(plist);
	//LTPopBack(plist);
	LTPrint(plist);

	LTErase(p2);
	LTPrint(plist);

	LTErase(p1);
	LTPrint(plist);

	LTPopFront(plist);
	LTPopFront(plist);
	LTPopFront(plist);
	//LTPopFront(plist);
	LTPrint(plist);

	LTDestroy(plist);
}

int main()
{
	test1();
	return 0;
}
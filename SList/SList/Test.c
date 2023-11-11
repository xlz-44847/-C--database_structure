#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void test1()
{
	SLNode* plist = NULL;
	SLTPushBack(&plist, 4);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 1);

	SLNode* p1 = SLTFind(plist, 2);
	SLTInsert(&plist, p1, 8);
	SLTPrint(plist);

	SLNode* p2 = SLTFind(plist, 4);
	SLTInsert(&plist, p2, 9);
	SLTPrint(plist);

	SLTErase(&plist,p1);
	SLTPrint(plist);

	SLTPopFront(&plist);
	SLTPrint(plist);

	SLTErase(&plist,p2);
	SLTPrint(plist);

	SLTPopFront(&plist);
	SLTPrint(plist);

	SLTPopFront(&plist);
	SLTPrint(plist);

	//SLTPopFront(&plist);
	//SLTPrint(plist);
}
void test2()
{
	SLNode* plist = NULL;
	SLTPushFront(&plist, 4);
	SLTPushFront(&plist, 3);
	SLTPushFront(&plist, 2);
	SLTPushFront(&plist, 1);
	SLTPrint(plist);

	SLNode* p1 = SLTFind(plist, 3);
	SLTInsertAfter(&plist, p1, 8);
	SLTPrint(plist);

	SLNode* p2 = SLTFind(plist, 1);
	SLTInsertAfter(&plist, p2, 9);
	SLTPrint(plist);

	SLTEraseAfter(&plist, p1);
	SLTPrint(plist);

	SLTEraseAfter(&plist, p2);
	SLTPrint(plist);

	SLTPopBack(&plist);
	SLTPrint(plist);

	SLTPopBack(&plist);
	SLTPrint(plist);

	SLTPopBack(&plist);
	SLTPrint(plist);

	//SLTPopBack(&plist);
	//SLTPrint(plist);

	SLTDestroy(&plist);
}

int main()
{

	test2();

	return 0;
 }
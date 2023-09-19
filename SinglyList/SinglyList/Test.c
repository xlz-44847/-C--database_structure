#define _CRT_SECURE_NO_WARNINGS 
#include"SList.h"

int main()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushFront(&plist, 0);
	SListPushFront(&plist, -1);
	SListPushFront(&plist, -2);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPrint(plist);
	SListInsert(&plist, 1, 0);
	SListPrint(plist);
	SListInsert(&plist, 1, 2);
	SListPrint(plist);
	SListInsertAfter(&plist, 1, 3);
	SListPrint(plist);
	SListInsertAfter(&plist, 1, 4);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);
	SListErase(&plist,0);
	SListPrint(plist);
	SListErase(&plist,1);
	SListPrint(plist);
	SListDestory(&plist);
	SListPrint(plist);
	return 0;
}
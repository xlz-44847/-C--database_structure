#define _CRT_SECURE_NO_WARNINGS 
#include"SeqList.h"

void main()
{
	SL s; //����˳���
	SLInit(&s);
	SLPushFront(&s, 1);
	SLPushBack(&s, 2);
	SLPushFront(&s, 3);
	SLPushBack(&s, 4);
	SLPushFront(&s, 5);
	SLPushBack(&s, 6);
	SLPushFront(&s, 7);
	SLPrint(&s);
	SLInsert(&s, 9, 5);
	SLPrint(&s);
	SLPopBack(&s);
	SLPopFront(&s);
	SLPopBack(&s);
	SLPopFront(&s);
	SLPrint(&s);
	SLErase(&s, 2);
	SLPrint(&s);
	int ret = SLFind(&s, 1);
	if (ret == -1)
		printf("δ�ҵ�");
	else
		printf("�����±�Ϊ��%d\n", ret);
	SLDestory(&s);
}
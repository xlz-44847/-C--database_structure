#define _CRT_SECURE_NO_WARNINGS 

#include"List.h"

LTNode* BuyNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		printf("malloc fail");
		exit(-1);
	}
	newnode->prev = NULL;
	newnode->next = NULL;
	newnode->data = x;
	return newnode;
}

LTNode* ListInit()
{
	LTNode* phead = BuyNode(-1);
	phead->prev = phead;
	phead->next = phead;
	return phead;
}

void ListPrint(LTNode* phead)
{
	assert(phead);

	LTNode* tmp = phead->next;
	printf("head<=>");
	while (tmp != phead)
	{
		printf("%d<=>", tmp->data);
		tmp = tmp->next;
	}
	printf("head\n");
}

void ListDestroy(LTNode* phead)
{
	assert(phead);

	LTNode* tmp = phead->next;
	while (tmp != phead )
	{
		LTNode* next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(phead);
}

void ListPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* newnode = BuyNode(x);
	LTNode* first = phead->next;
	first->prev = newnode;
	newnode->next = first;
	newnode->prev = phead;
	phead->next = newnode;
}

void ListPushBack(LTNode* phead,LTDataType x)
{
	assert(phead);

	LTNode* newnode = BuyNode(x);
	LTNode* tail = phead->prev;
	tail->next = newnode;
	newnode->next = phead;
	newnode->prev = tail;
	phead->prev = newnode;
}

void ListPopFront(LTNode* phead)
{
	assert(phead);

	if (phead->next == phead)
	{
		return;
	}
	else
	{
		LTNode* tmp = phead->next;
		phead->next = tmp->next;
		tmp->next->prev = phead;
		free(tmp);
	}
}

void ListPopBack(LTNode* phead)
{
	assert(phead);

	if (phead->prev == phead)
	{
		return;
	}
	else
	{
		LTNode* tmp = phead->prev;
		phead->prev = tmp->prev;
		tmp->prev->next = phead;
		free(tmp);
	}
}

LTNode* ListFind(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void ListInsert(LTNode* pos, LTDataType x)
{
	if (pos == NULL)
	{
		printf("未找到节点\n");
		return;
	}
	else
	{
		LTNode* tmp = BuyNode(x);
		LTNode* former = pos->prev;
		former->next = tmp;
		pos->prev = tmp;
		tmp->prev = former;
		tmp->next = pos;
	}
}

void ListErase(LTNode* pos)
{
	if (pos == NULL)
	{
		printf("未找到节点\n");
		return;
	}
	else
	{
		LTNode* tmp = pos->prev;
		LTNode* late = pos->next;
		tmp->next = late;
		late->prev = tmp;
		free(pos);
	}
}
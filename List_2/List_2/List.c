#define _CRT_SECURE_NO_WARNINGS 
#include"List.h"

LTNode* CreateLTNode(LTDataType x)
{
	LTNode* tmp = (LTNode*)malloc(sizeof(LTNode));
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	tmp->val = x;
	tmp->next = NULL;
	tmp->prev = NULL;
	return tmp;
}

LTNode* LTInit()
{
	LTNode* tmp = CreateLTNode(-1);
	tmp->next = tmp;
	tmp->prev = tmp;
	return tmp;
}

void LTPrint(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d<=>", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}

void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* tail = phead->prev;
	LTNode* tmp = CreateLTNode(x);
	tmp->next = phead;
	tmp->prev = tail;
	tail->next = tmp;
	phead->prev = tmp;
}

void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* tmp = CreateLTNode(x);
	tmp->next = phead->next;
	tmp->next->prev = tmp;
	phead->next = tmp;
	tmp->prev = phead;
}

void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	LTNode* tail = phead->prev;
	phead->prev = tail->prev;
	tail->prev->next = phead;
	free(tail);
	tail = NULL;
}

void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	LTNode* first = phead->next;
	phead->next = first->next;
	first->prev = phead;
	free(first);
	first = NULL;
}

LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->val == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

//在pos前插入
void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	
	LTNode* tmp = CreateLTNode(x);
	tmp->next = pos;
	tmp->prev = pos->prev;
	tmp->prev->next = tmp;
	pos->prev = tmp;
}

//删除pos位置节点
void LTErase(LTNode* pos)
{
	assert(pos);

	LTNode* prepos = pos->prev;
	prepos->next = pos->next;
	pos->next->prev = prepos;
	free(pos);
	pos = NULL;
}

void LTDestroy(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}
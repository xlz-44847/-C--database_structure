#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void SLTPrint(SLNode* phead)
{
	while (phead != NULL)
	{
		printf("%d->", phead->val);
		phead = phead->next;
	}
	printf("NULL\n");
}

SLNode* CreateNode(SLNDataType x)
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	newnode->val = x;
	newnode->next = NULL;
	return newnode;
}

void SLTPushBack(SLNode** pphead, SLNDataType x)
{
	assert(pphead);

	if (*pphead == NULL)
	{
		*pphead = CreateNode(x);
	}
	else
	{
		SLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = CreateNode(x);
	}
}

void SLTPushFront(SLNode** pphead, SLNDataType x)
{
	assert(pphead);

	SLNode* tmp = CreateNode(x);
	tmp->next = *pphead;
	*pphead = tmp;
}

void SLTPopBack(SLNode** pphead)
{
	assert(pphead);
	//0个节点
	assert(*pphead);
	//1个节点
	SLNode* prev = NULL;
	SLNode* tail = *pphead;
	if (tail->next == NULL)
	{
		free(tail);
		tail = NULL;
		*pphead = NULL;
	}
	else
	{
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}

void SLTPopFront(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	SLNode* tmp = NULL;
	*pphead = (*pphead)->next;
	free(tmp);
	tmp = NULL;
}

SLNode* SLTFind(SLNode* phead, SLNDataType x)
{

	SLNode* tmp = phead;
	while (tmp != NULL)
	{
		if (tmp->val == x)
		{
			return tmp;
		}
		else
		{
			tmp = tmp->next;
		}
	}
	printf("未找到节点\n");
	return NULL;
}

//在pos节点前插入
void SLTInsert(SLNode** pphead, SLNode* pos, SLNDataType x)
{
	assert(pphead);
	assert(*pphead);
	assert(pos);

	SLNode* tmp = CreateNode(x);
	if (pos == *pphead)
	{
		tmp->next = *pphead;
		*pphead = tmp;
	}
	else
	{
		SLNode* prev = *pphead;
		tmp->next = pos;
		while (prev->next != pos)
		{
			//if (prev->next == NULL)
			//{
			//	printf("插入节点有误\n");
			//	exit(-1);
			//}
			prev = prev->next;
		}
		prev->next = tmp;
	}
}

//删除pos节点
void SLTErase(SLNode** pphead, SLNode* pos)
{
	assert(pphead);
	assert(*pphead);
	assert(pos);
	
	if (pos == *pphead)
	{
		SLNode* tmp = *pphead;
		*pphead = (*pphead)->next;
		free(tmp);
		tmp = NULL;
	}
	else
	{
		SLNode* prev = *pphead;
		while (prev->next != pos)
		{
			/*if (prev->next == NULL)
			{
				printf("删除节点有误\n");
				exit(-1);
			}*/
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

//在pos位置后插入
void SLTInsertAfter(SLNode** pphead, SLNode* pos, SLNDataType x)
{
	assert(pphead);
	assert(pos);

	SLNode* tmp = CreateNode(x);
	tmp->next = pos->next;
	pos->next = tmp;
}

//在pos位置后删除
void SLTEraseAfter(SLNode** pphead, SLNode* pos)
{
	assert(pphead);
	assert(pos);
	assert(pos->next);

	SLNode* tmp = pos->next;
	pos->next = tmp->next;
	free(tmp);
	tmp = NULL;
}

void SLTDestroy(SLNode** pphead)
{
	while (*pphead != NULL)
	{
		SLNode* tmp = *pphead;
		*pphead = (*pphead)->next;
		free(tmp);
		tmp = NULL;
	}
}
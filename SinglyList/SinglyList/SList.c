#define _CRT_SECURE_NO_WARNINGS 
#include"SList.h"

void SListPrint(const SLTNode* phead)
{
	while (phead)
	{
		printf("%d->", phead->data);
		phead = phead->next;
	}
	printf("NULL\n");
}

void SListDestory(SLTNode** pphead)
{
	assert(pphead);
	
	SLTNode* cur = NULL;
	while (*pphead)
	{
		cur = (*pphead)->next;
		free(*pphead);
		*pphead = cur;
	}
}

SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		printf("malloc fail");
		exit(-1);
	}
	else
	{
		newnode->data = x;
		newnode->next = NULL;
	}
	return newnode;
}

void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);

	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
	
}

void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);

	SLTNode* newnode = BuySLTNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* cur = *pphead;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newnode;
	}
}

void SListPopFront(SLTNode** pphead)
{
	assert(pphead);

	if (*pphead == NULL)
	{
		return;
	}
	SLTNode* temp = *pphead;
	*pphead = temp->next;
	free(temp);
	temp = NULL;
}

void SListPopBack(SLTNode** pphead)
{
	assert(pphead);

	if (*pphead == NULL)
	{
		return;
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* pre = NULL;
		SLTNode* cur = *pphead;
		while (cur->next != NULL)
		{
			pre = cur;
			cur = cur->next;
		}
		free(cur);
		pre->next = NULL;
	}
}

SLTNode* SListFind(SLTNode* phead,SLTDataType x)
{
	while (phead->data != x && phead != NULL)
	{
		phead = phead->next;
	}
	return phead;
}

void SListInsert(SLTNode** pphead, SLTDataType pos, SLTDataType x)//在data为pos前插入节点
{
	assert(pphead);

	SLTNode* loc = SListFind(*pphead, pos);
	if (loc == NULL)
	{
		printf("cannot find this data");
		return;
	}
	else
	{
		if (loc == *pphead)
		{
			SListPushFront(pphead, x);
		}
		else
		{
			SLTNode* temp = BuySLTNode(x);
			temp->next = loc;
			SLTNode* pre = *pphead;
			while (pre->next != loc)
			{
				pre = pre->next;
			}
			pre->next = temp;
		}
	}
}

void SListInsertAfter(SLTNode** pphead, SLTDataType pos, SLTDataType x)
{
	assert(pphead);

	SLTNode* loc = SListFind(*pphead, pos);
	if (loc == NULL)
	{
		printf("cannot find this data");
		return;
	}
	else
	{
		SLTNode* temp = BuySLTNode(x);
		temp->next = loc->next;
		loc->next = temp;
	}
}

void SListErase(SLTNode** pphead, SLTDataType pos)
{
	assert(pphead);

	SLTNode* loc = SListFind(*pphead, pos);
	if (loc == NULL)
	{
		printf("cannot find this data");
		return;
	}
	else
	{
		if (*pphead == loc)
		{
			SListPopFront(pphead);
		}
		else
		{
			SLTNode* pre = *pphead;
			while (pre->next != loc)
			{
				pre = pre->next;
			}
			pre->next = loc->next;
			free(loc);
		}
	}
}
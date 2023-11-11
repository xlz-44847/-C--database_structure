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
	//0���ڵ�
	assert(*pphead);
	//1���ڵ�
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
	printf("δ�ҵ��ڵ�\n");
	return NULL;
}

//��pos�ڵ�ǰ����
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
			//	printf("����ڵ�����\n");
			//	exit(-1);
			//}
			prev = prev->next;
		}
		prev->next = tmp;
	}
}

//ɾ��pos�ڵ�
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
				printf("ɾ���ڵ�����\n");
				exit(-1);
			}*/
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

//��posλ�ú����
void SLTInsertAfter(SLNode** pphead, SLNode* pos, SLNDataType x)
{
	assert(pphead);
	assert(pos);

	SLNode* tmp = CreateNode(x);
	tmp->next = pos->next;
	pos->next = tmp;
}

//��posλ�ú�ɾ��
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
#define _CRT_SECURE_NO_WARNINGS 
#include"SeqList.h"

void SLInit(SL* ps1)
{
	assert(ps1);

	ps1->a = NULL;
	ps1->size = 0;
	ps1->capacity = 0;
}

void SLPrint(const SL* ps1)
{
	assert(ps1);

	for (int i = 0; i < ps1->size; i++)
	{
		printf("%d ", ps1->a[i]);
	}
	printf("\n");
}

void SLDestory(SL* ps1)
{
	assert(ps1);

	free(ps1->a);
	ps1->a = NULL;
	ps1->capacity = 0;
	ps1->size = 0;
}

void SLCheckCapacity(SL* ps1)
{
	if (ps1->size == ps1->capacity)
	{
		int newcapacity = ps1->capacity == 0 ? 4 : ps1->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps1->a, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		ps1->a = tmp;
		ps1->capacity = newcapacity;
	}
}

void SLPushFront(SL* ps1, SLDataType x)
{
	assert(ps1);

	SLCheckCapacity(ps1);
	for (int i = ps1->size; i > 0; i--)
		ps1->a[i] = ps1->a[i - 1];
	ps1->a[0] = x;
	ps1->size++;
}

void SLPushBack(SL* ps1, SLDataType x)
{
	assert(ps1);

	SLCheckCapacity(ps1);
	ps1->a[ps1->size] = x;
	ps1->size++;
}

void SLInsert(SL* ps1, SLDataType x, size_t pos)
{
	assert(ps1);

	SLCheckCapacity(ps1);
	for (int i = ps1->size; i > pos; i--)
		ps1->a[i] = ps1->a[i - 1];
	ps1->a[pos] = x;
	ps1->size++;
}

void SLPopFront(SL* ps1)
{
	assert(ps1);
	//检查是否有元素可以删除
	assert(ps1->size > 0);

	for (int i = 0; i < ps1->size - 1; i++)
		ps1->a[i] = ps1->a[i + 1];
	ps1->size--;
}

void SLPopBack(SL* ps1)
{
	assert(ps1);
	//检查是否有元素可以删除
	assert(ps1->size > 0);

	ps1->size--;
}

void SLErase(SL* ps1, size_t pos)
{
	assert(ps1);
	//检查是否有元素可以删除
	assert(ps1->size > 0);

	for (int i = pos; i < ps1->size; i++)
		ps1->a[i] = ps1->a[i + 1];
	ps1->size--;
}

int SLFind(SL* ps1, SLDataType x)//找到返回下标，找不到返回-1
{
	assert(ps1);

	int i;
	for (i = 0; i < ps1->size; i++)
	{
		if (ps1->a[i] == x)
			return i;
	}
	if (i == ps1->size)
		return -1;
}
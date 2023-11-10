#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void SeqListInit(SL* ps)
{
	assert(ps);

	ps->size = 0;
	ps->capacity = 0;
	ps->data = NULL;
}

void SeqListDestroy(SL* ps)
{
	assert(ps);

	if (ps->data != NULL)
	{
		ps->size = 0;
		ps->capacity = 0;
		free(ps->data);
		ps->data = NULL;
	}
}

void SeqListPrint(SL* ps)
{
	assert(ps);

	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->data[i]);
	}
	printf("\n");
}

void CheckCapacity(SL* ps)
{
	if (ps->size < ps->capacity)
	{
		return;
	}
	else
	{
		int newcapacity = ps->capacity == 0 ? 4 : 2 * (ps->capacity);
		SLDataType* tmp = (SLDataType*)realloc(ps->data, sizeof(SLDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		ps->data = tmp;
		ps->capacity = newcapacity;
	}
}

void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);

	CheckCapacity(ps);

	ps->data[ps->size] = x;
	ps->size++;
}

void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);

	CheckCapacity(ps);

	int tmp = ps->size;
	while (tmp)
	{
		ps->data[tmp] = ps->data[tmp - 1];
		tmp--;
	}
	ps->data[0] = x;
	ps->size++;
}

void SLPopBack(SL* ps)
{
	assert(ps);

	assert(ps->size > 0);

	ps->size--;
}

void SLPopFront(SL* ps)
{
	assert(ps);

	assert(ps->size > 0);

	int tmp = 0;
	while (tmp < ps->size - 1)
	{
		ps->data[tmp] = ps->data[tmp + 1];
		tmp++;
	}
	ps->size--;
}

// pos是下标,在下标为pos的位置插入或删除
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);

	CheckCapacity(ps);

	int tmp = ps->size;
	while (tmp > pos)
	{
		ps->data[tmp] = ps->data[tmp - 1];
		tmp--;
	}
	ps->data[pos] = x;
	ps->size++;
}

void SLErase(SL* ps, int pos)
{
	assert(ps);

	assert(ps->size > 0);
	
	int tmp = pos;
	while (tmp < ps->size - 1)
	{
		ps->data[tmp] = ps->data[tmp + 1];
		tmp++;
	}
	ps->size--;
}

int SLFind(SL* ps, SLDataType x)
{
	assert(ps);

	for (int i = 0; i < ps->size; i++)
	{
		if (ps->data[i] == x)
		{
			return i;
		}
	}
	return -1;
}
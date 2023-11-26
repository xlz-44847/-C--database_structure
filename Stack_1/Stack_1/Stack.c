#define _CRT_SECURE_NO_WARNINGS 
#include"Stack.h"

void STInit(ST* pst)
{
	assert(pst);

	pst->data = NULL;
	pst->top = -1;
	pst->capacity = 0;
}

void STPush(ST* pst,STDataType x)
{
	assert(pst);

	if (pst->top + 1 == pst->capacity)
	{
		int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		ST* tmp = realloc(pst->data, newcapacity*sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		pst->data = tmp;
		pst->capacity = newcapacity;
	}
	pst->top++;
	pst->data[pst->top] = x;
}

void STPop(ST* pst)
{
	assert(pst);
	assert(pst->top != -1);

	pst->top--;
}

bool STEmpty(ST* pst)
{
	assert(pst);

	return pst->top == -1;
}

STDataType STTop(ST* pst)
{
	assert(pst);
	assert(pst->top != -1);

	return pst->data[pst->top];
}

int STSize(ST* pst)
{
	assert(pst);

	return pst->top + 1;
}

void STDestroy(ST* pst)
{
	assert(pst);

	free(pst->data);
	pst->data = NULL;
	pst->capacity = 0;
	pst->top = -1;
}
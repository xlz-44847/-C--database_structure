#include "heap.h"

void HeapInit(HP* php)
{
	assert(php);

	php->data = NULL;
	php->capacity = php->size = 0;
}

void HeapDestroy(HP* php)
{
	assert(php);

	free(php->data);
	php->data = NULL;
	php->capacity = php->size = 0;
}

void Swap(HPDataType* a, HPDataType* b)
{
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}

//小堆
void AdjustUp(HP* php)
{
	int child = php->size - 1;
	int parent = (php->size - 1) / 2;
	while (child > 0)
	{
		if(php->data[child] < php->data[parent])
		{
			Swap(&php->data[child], &php->data[parent]);
			child = parent;
			parent = (parent - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(HP* php, HPDataType x)
{
	assert(php);

	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		HPDataType* tmp = realloc(php->data, sizeof(int) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		else
		{
			php->data = tmp;
		}
		php->capacity = newcapacity;
	}

	php->data[php->size] = x;
	php->size++;
	AdjustUp(php);
}

void AdjustDown(HP* php)
{
	int parent = 0;
	int child = parent * 2 + 1;
	while (child < php->size)
	{
		//选择较小的孩子
		if (child + 1 < php->size && php->data[child] > php->data[child + 1])
		{
			child++;
		}

		if (php->data[parent] > php->data[child])
		{
			Swap(&php->data[parent], &php->data[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(HP* php)
{
	assert(php);

	Swap(&php->data[0], &php->data[php->size - 1]);
	php->size--;
	AdjustDown(php);
}

int HeapSize(HP* php)
{
	assert(php);

	return php->size;
}

bool HeapEmpty(HP* php)
{
	assert(php);

	return php->size == 0;
}

HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	return php->data[php->size - 1];
}
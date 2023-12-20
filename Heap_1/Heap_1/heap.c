#define _CRT_SECURE_NO_WARNINGS 

#include"heap.h"

void HeapInit(HP* php)
{
	assert(php);

	php->data = NULL;
	php->size = 0;
	php->capacity = 0;
}

void HeapDestroy(HP* php)
{
	assert(php);

	free(php->data);
	php->data = NULL;
	php->size = php->capacity = 0;
}

void swap(void* e1, void* e2, int width)
{
	for (int i = 0; i < width; i++)
	{
		char tmp = *((char*)e1 + i);
		*((char*)e1 + i) = *((char*)e2 + i);
		*((char*)e2 + i) = tmp;
	}
}

void AdjustUp(HPDataType* arr, int child, int width, bool cmp(const void*, const void*))
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (cmp(arr + child, arr + parent))
		{
			swap(arr + child, arr + parent, width);
			child = parent;
			parent = (parent - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(HP* php, HPDataType x, bool cmp(const void*, const void*))
{
	assert(php);

	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		HPDataType* tmp = realloc(php->data, newcapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		php->data = tmp;
		php->capacity = newcapacity;
	}
	php->data[php->size] = x;
	php->size++;
	AdjustUp(php->data, php->size - 1, sizeof(HPDataType), cmp);
}

void AdjustDown(HPDataType* arr, int parent, int size, int width, bool cmp(const void*, const void*))
{
	int child = parent * 2 + 1;

	while (child < size)
	{
		//选出左右孩子中较小（小堆）或较大（大堆）的一个
		//小堆后大于前为真，大堆前大于后为真
		if (child + 1 < size && cmp(arr + child + 1, arr + child))
		{
			child = child + 1;
		}
		//将选出的孩子与父亲比较，符合堆的结构就停止，否则继续向下调整
		if (cmp(arr + parent, arr + child))
		{
			break;
		}
		else
		{
			swap(arr + parent, arr + child, width);
			parent = child;
			child = parent * 2 + 1;
		}
	}
}

void HeapPop(HP* php, bool cmp(const void*, const void*))
{
	assert(php);
	assert(php->size);

	swap(php->data, php->data + php->size - 1, sizeof(HPDataType));
	php->size--;
	AdjustDown(php->data, 0, php->size, sizeof(HPDataType), cmp);
}

int HeapSize(HP* php)
{
	return php->size;
}

bool HeapEmpty(HP* php)
{
	return php->size == 0;
}

HPDataType HeapTop(HP* php)
{
	return php->data[php->size - 1];
}
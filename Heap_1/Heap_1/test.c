#define _CRT_SECURE_NO_WARNINGS 

#include"heap.h"

//后大于前为真
bool cmp_small_heap(const void* e1, const void* e2)
{
	if (*(HPDataType*)e2 > *(HPDataType*)e1)
		return true;
	else
		return false;
}

//前大于后为真
bool cmp_large_heap(const void* e1, const void* e2)
{
	if (*(HPDataType*)e1 > *(HPDataType*)e2)
		return true;
	else
		return false;
}

int main()
{
	HP hp;
	int arr[10] = { 5,7,9,2,1,4,6,0,3,8 };
	HeapInit(&hp);
	for (int i = 0; i < 10; i++)
	{
		//HeapPush(&hp, arr[i],cmp_small_heap);
		HeapPush(&hp, arr[i],cmp_large_heap);
	}
	//HeapPop(&hp,cmp_small_heap);
	HeapPop(&hp,cmp_large_heap);
	HeapDestroy(&hp);
	return 0;
}
#include"heap.h"

int main()
{
	HP hp;
	int arr[10] = { 5,7,9,2,1,4,6,0,3,8 };
	HeapInit(&hp);
	for (int i = 0; i < 10; i++)
	{
		HeapPush(&hp, arr[i]);
	}
	HeapPop(&hp);
	//HeapPush(&hp, 1);
	HeapDestroy(&hp);
	return 0;
}
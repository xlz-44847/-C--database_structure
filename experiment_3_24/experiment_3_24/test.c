#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct ListNode
{
	int val;
	struct ListNode* prev;
	struct ListNode* next;
}Node;

Node* CreateNode(int x)
{
	Node* ret = (Node*)malloc(sizeof(Node));
	if (ret == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	ret->val = x;
	ret->prev = NULL;
	ret->next = NULL;
	return ret;
}

Node* ListInit(int x)
{
	Node* phead = CreateNode(0);
	phead->val = x;
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

void InsertNode(Node* phead, int pos, int x)
{
	Node* tmp = CreateNode(x);
	if (pos == -1)
	{
		tmp->prev = phead->prev;
		tmp->next = phead;
		tmp->prev->next = tmp;
		phead->prev = tmp;
	}
	else
	{
		Node* cur = phead;
		while (pos--)
		{
			cur = cur->next;
		}
		tmp->prev = cur->prev;
		tmp->next = cur;
		tmp->prev->next = tmp;
		cur->prev = tmp;
	}
}

void Print(Node* phead, int k)
{
	Node* cur = phead;
	printf("%d.", cur->val);
	while (k--)
	{
		cur = cur->next;
		printf("%d", cur->val);
	}

}

void ListDestroy(Node** phead)
{
	Node* cur = (*phead)->next;
	while (cur != (*phead))
	{
		Node* tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	free(cur);
	*phead = NULL;
}
void Test()
{
	Node* plist = ListInit(0);
	InsertNode(plist, -1, 4);
	InsertNode(plist, 1, 1);
	InsertNode(plist, 2, 2);
	InsertNode(plist, 3, 3);
	Print(plist,4);
	ListDestroy(&plist);
}

int Add(int x, int y, int* ci)
{
	int ret = x + y + *ci;
	*ci = ret / 10;
	return ret % 10;
}

////传入分子分母，得到相除的结果
//Node* getdivnum(int upper, int lower)
//{
//	//构造新的乘数
//	Node* num = ListInit(0);
//	for (int i = 0; i < n + n / 2; i++)
//	{
//		InsertNode(num, -1, 0);
//	}
//
//	Node* cur = num;
//	do {
//		cur->val = upper / lower;
//		upper = (upper % lower) * 10;
//		cur = cur->next;
//	} while (cur != num);
//
//	return num;
//}

void mul(Node* num, int x)
{
	int ci = 0;
	Node* cur = num->prev;
	do {
		cur->val = Add(0, cur->val * x, &ci);

		cur = cur->prev;
	} while (cur != num->prev);
}

void _div(Node* num, int x)
{
	int ci = 0;
	Node* cur = num;
	do {
		ci += cur->val;
		cur->val = ci / x;
		ci = ci % x;
		ci *= 10;

		cur = cur->next;
	} while (cur != num);
}

//1 + 1*1/3 + 1*1/3*2/5 + ...
//i是第i项
void getsum(Node* sum, int i)
{	
	//1.sum*分子
	int upper = i == 0 ? 1 : i;//分子
	mul(sum, upper);

	//2.sum/分母
	int lower = i * 2 + 1;//分母
	_div(sum, lower);
}

void add(Node* p1, Node* p2)
{
	int ci = 0;
	Node* cur1 = p1->prev;
	Node* cur2 = p2->prev;
	do {
		cur1->val = Add(cur1->val, cur2->val, &ci);

		cur1 = cur1->prev;
		cur2 = cur2->prev;
	} while (cur1 != p1->prev);
}

int n;
int main()
{
	scanf("%d", &n);
	
	Node* pi = ListInit(0);
	for (int i = 0; i < n + n / 2; i++)
	{
		InsertNode(pi, -1, 0);
	}

	Node* sum = ListInit(1);
	for (int i = 0; i < n + n / 2; i++)
	{
		InsertNode(sum, -1, 0);
	}

	//Node* ele = ListInit(1);
	//for (int i = 0; i < n + n / 2; i++)
	//{
	//	InsertNode(ele, -1, 0);
	//}

	int count = (int)(n / 0.2);
	for (int i = 0; i < count; i++)
	{
		getsum(sum, i);
		add(pi, sum);
	}

	mul(pi, 2);

	Print(pi,n);
	return 0;
}


//int main()
//{
//    int len1, len2;
//    int arr1[20], arr2[20];
//    scanf("%d", &len1);
//    for (int i = 0; i < len1; i++)
//    {
//        scanf("%d", &arr1[i]);
//    }
//    scanf("%d", &len2);
//    for (int i = 0; i < len2; i++)
//    {
//        scanf("%d", &arr2[i]);
//    }
//    int arr3[40];
//    int n1 = 0, n2 = 0, n3 = 0;
//    while (n1 < len1 && n2 < len2)
//    {
//        if (arr1[n1] < arr2[n2])
//        {
//            arr3[n3++] = arr1[n1++];
//        }
//        else
//        {
//            arr3[n3++] = arr2[n2++];
//        }
//    }
//    while (n1 < len1)
//    {
//        arr3[n3++] = arr1[n1++];
//    }
//    while (n2 < len2)
//    {
//        arr3[n3++] = arr2[n2++];
//    }
//    for (int i = 0; i < n3; i++)
//    {
//        printf("%d\n", arr3[i]);
//    }
//    return 0;
//}
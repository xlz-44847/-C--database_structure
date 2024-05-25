//请使用C语言进行编程
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int val;
    struct Node* next;
}Node;
Node* BuyNode(int x)
{
    Node* ret = (Node*)malloc(sizeof(Node));
    ret->val = x;
    ret->next = NULL;
}
int main()
{
    int m, n;
    scanf("%d%d", &n, &m);
    Node* arr[100];
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        arr[num] = BuyNode(num);
    }
    while (m--)
    {
        int num1, num2;
        scanf("%d%d", &num1, &num2);
        Node* cur = arr[num1];
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = BuyNode(num2);
    }
    int num1, num2;
    scanf("%d%d", &num1, &num2);
    Node* cur = arr[num1];
    while (cur->next != NULL)
    {
        if (cur->val == num2)
        {
            printf("yes\n");
            return 0;
        }
        cur = cur->next;
    }
    printf("no\n");
    return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void reverse(int* arr, int begin, int end)
{
    while (begin < end)
    {
        int tmp = arr[begin];
        arr[begin] = arr[end];
        arr[end] = tmp;
        begin++;
        end--;
    }
}
int main()
{
    int n, k;
    int a[100];
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    reverse(a, 0, k % n - 1);
    reverse(a, k % n, n - 1);
    reverse(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
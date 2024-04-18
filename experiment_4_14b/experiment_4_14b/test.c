#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void main()
{
	int m, n, t1, t2;
	scanf("%d%d%d%d", &m, &n, &t1, &t2);
	int arr[20][20];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			arr[i][j] = 0;
	int r = 0, c = 0, val = 0;
	for (int i = 0; i < t1 + t2; i++)
	{
		scanf("%d%d%d", &r, &c, &val);
		arr[r][c] += val;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] != 0)
			{
				printf("%d %d %d\n", i, j, arr[i][j]);
			}
		}
	}
}
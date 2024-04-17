#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void Test1()
{
	int n, m;
	scanf("%d%d", &m, &n);
	int arr[20][20];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			arr[i][j] = 0;
	int r = 0, c = 0, val = 0;
	scanf("%d%d%d", &r, &c, &val);
	int cou = 0;
	while (r != 0 || c != 0 || val != 0)
	{
		arr[r][c] = val;
		scanf("%d%d%d", &r, &c, &val);
	}
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < m; i++)
		{
			if (arr[i][j] != 0)
			{
				printf("%d %d %d\n", j, i, arr[i][j]);
			}
		}
	}
}

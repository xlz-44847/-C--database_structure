#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void main()
{
	int n1, m1;
	scanf("%d%d", &m1, &n1);
	int arr1[20][20];
	for (int i = 0; i < m1; i++)
		for (int j = 0; j < n1; j++)
			arr1[i][j] = 0;
	int r = 0, c = 0, val = 0;
	scanf("%d%d%d", &r, &c, &val);
	while (r != 0 || c != 0 || val != 0)
	{
		arr1[r-1][c-1] = val;
		scanf("%d%d%d", &r, &c, &val);
	}
	int n2, m2;
	scanf("%d%d", &m2, &n2);
	int arr2[20][20];
	for (int i = 0; i < m2; i++)
		for (int j = 0; j < n2; j++)
			arr2[i][j] = 0;
	scanf("%d%d%d", &r, &c, &val);
	while (r != 0 || c != 0 || val != 0)
	{
		arr2[r-1][c-1] = val;
		scanf("%d%d%d", &r, &c, &val);
	}

	int sum = 0;
	for (int i = 0; i < m1; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			for (int k = 0; k < m2; k++)
			{
				sum += arr1[i][k] * arr2[k][j];
			}
			if (sum != 0)
			{
				printf("%d %d %d\n", i + 1, j + 1, sum);
				sum = 0;
			}
		}
	}
}
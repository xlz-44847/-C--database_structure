#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void PrintPath(int x, int y, int(*path)[100])
{
	if (path[x][y] != x)
	{
		PrintPath(x, path[x][y], path);
	}
	printf("%d\n", path[x][y]);
}

int main()
{
	int data[100][100];
	int path[100][100];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &data[i][j]);
			if (i == j || data[i][j] == 10000) path[i][j] = -1;
			else path[i][j] = i;
		}
	}
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i != k && j != k && i != j)
				{
					if (data[i][k] != 10000 && data[k][j] != 10000 && data[i][j] > data[i][k] + data[k][j])
					{
						data[i][j] = data[i][k] + data[k][j];
						path[i][j] = path[k][j];
					}
				}
			}
		}
	}
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		//printf("%d\n", data[x][y]);
		PrintPath(x, y, path);
		printf("%d\n", y);
	}
}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;

typedef struct HuffmanTree
{
	int n;
	char c;
	int lchild, rchild, parent;
}htree;

htree tree[201];
char chs[101];
char code[100][201];
int wei[101];

void createtree()
{
	tree[0].n = 0;
	for (int i = 1; i <= n; i++)
	{
		tree[i].c = chs[i];
		tree[i].n = wei[i];
		tree[i].lchild = tree[i].rchild = tree[i].parent = 0;
	}
	for (int i = n + 1; i < 2 * n; i++)
	{
		int m1 = INT_MAX, m2 = INT_MAX, mi1 = 0, mi2 = 0;
		for (int j = 1; j < i; j++)
		{
			if (tree[j].parent == 0)
			{
				if (tree[j].n < m1)
				{
					m2 = m1;
					m1 = tree[j].n;
					mi2 = mi1;
					mi1 = j;
				}
				else if (tree[j].n < m2)
				{
					m2 = tree[j].n;
					mi2 = j;
				}
			}
		}
		tree[mi1].parent = tree[mi2].parent = i;
		tree[i].lchild = mi1;
		tree[i].rchild = mi2;
		tree[i].n = tree[mi1].n + tree[mi2].n;
	}
	tree[2 * n - 1].parent = 0;
}

void hufcode()
{
	for (int i = 1; i <= n; i++)
	{
		char tmp[100];
		int cou = 0;
		int cur = i;
		while (tree[cur].parent != 0)
		{
			
			if (tree[tree[cur].parent].lchild == cur)
			{
				tmp[cou++] = '0';
			}
			else
			{
				tmp[cou++] = '1';
			}
			cur = tree[cur].parent;
		}
		for (int j = 0; j < cou; j++)
		{
			code[i][j] = tmp[cou - j - 1];
		}
		code[i][cou] = '\0';
	}
}

void hufencode(char* str, char* ret)
{
	int start = 2 * n - 1;
	int cou = 0;
	int cur = start;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (tree[cur].lchild == 0 && tree[cur].rchild == 0)
		{
			//printf("%c", tree[cur].c);
			ret[cou++] = tree[cur].c;
			cur = start;
		}
		if (str[i] == '0')
		{
			cur = tree[cur].lchild;
		}
		else
		{
			cur = tree[cur].rchild;
		}
	}
	//printf("%c", tree[cur].c);
	ret[cou++] = tree[cur].c;
	ret[cou] = '\0';
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		getchar();
		chs[i] = getchar();
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", wei + i);
	}
	char s[100];
	scanf("%s", s);
	createtree();
	hufcode();
	char res[10000] = { 0 };
	for (int i = 0; s[i] != '\0'; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (s[i] == chs[j])
			{
				//printf("%s", code[j]);
				strcat(res, code[j]);
				break;
			}
		}
	}
	printf("%s\n", res);
	char ret[100];
	hufencode(res, ret);
	printf("%s\n", ret);
}

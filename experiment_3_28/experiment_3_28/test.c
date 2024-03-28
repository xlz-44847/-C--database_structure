#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
	char arr1[100],arr2[100];
	int k1 = 0, k2 = 0;
	scanf("%s", arr1);
	char ch = arr1[k1++];
	while (ch != '\0')
	{
		if (ch == '(' || ch == '[' || ch == '{')
		{
			arr2[k2++] = ch;
		}
		else if (ch == ')')
		{
			if (k2 - 1 >= 0 && arr2[k2 - 1] == '(')
			{
				k2--;
			}
			else
			{
				printf("no\n");
				return 0;
			}
		}
		else if (ch == ']')
		{
			if (k2 - 1 >= 0 && arr2[k2 - 1] == '[')
			{
				k2--;
			}
			else
			{
				printf("no\n");
				return 0;
			}
		}
		else if (ch == '}')
		{
			if (k2 - 1 >= 0 && arr2[k2 - 1] == '{')
			{
				k2--;
			}
			else
			{
				printf("no\n");
				return 0;
			}
		}
		ch = arr1[k1++];
	}
	if (k2 == 0)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
}
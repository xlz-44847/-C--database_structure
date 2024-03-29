#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct Stack
{
	char* a;
	size_t top;
}St;

void Init(St* s)
{
	s->a = (char*)malloc(sizeof(char) * 100);
	if (s->a == NULL)
	{
		perror("malloc fail");
		return;
	}
	s->top = 0;
}

void Push(St* s, char x)
{
	s->a[s->top] = x;
	s->top++;
}

void Pop(St* s)
{
	s->top--;
}

int Empty(St s)
{
	return s.top == 0;
}

char Top(St s)
{
	return s.a[s.top - 1];
}

int main()
{
	char arr[100];
	scanf("%s", arr);
	St s1, s2;
	Init(&s1);
	Init(&s2);
	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (arr[i] >= 'a' && arr[i] <= 'z')
		{
			Push(&s2, arr[i]);
		}
		else if(arr[i]=='(')
		{
			Push(&s1, arr[i]);
		}
		else if (arr[i] == ')')
		{
			while (Top(s1)!='(')
			{
				Push(&s2, Top(s1));
				Pop(&s1);
			}
			Pop(&s1);
		}
		else
		{
			if (Empty(s1) || Top(s1) == '(')
			{
				Push(&s1, arr[i]);
			}
			else if (arr[i] == '*' || arr[i] == '/')
			{
				if (Top(s1) == '+' || Top(s1) == '-')
				{
					Push(&s1, arr[i]);
				}
				else
				{
					Push(&s2, Top(s1));
					Pop(&s1);
					i--;
				}
			}
			else
			{
				Push(&s2, Top(s1));
				Pop(&s1);
				i--;
			}
		}
	}
	while (!Empty(s1))
	{
		Push(&s2, Top(s1));
		Pop(&s1);
	}
	s2.a[s2.top] = '\0';
	printf("%s", s2.a);
}
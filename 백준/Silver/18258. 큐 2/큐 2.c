#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[2000005] = { 0, };
int headdown = 0;
int headup = -1;

int empty(int* stack)
{
	if (headup + 1 == headdown)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(int* stack, int num)
{
	stack[++headup] = num;
}

int pop(int* stack)
{
	return stack[headdown++];
}

int size(int* stack)
{
	return headup - headdown + 1;
}

int front(int* stack)
{
	return stack[headdown];
}

int back(int* stack)
{
	return stack[headup];
}
int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		char str[10];
		scanf("%s", str);
		if (strcmp(str, "push") == 0)
		{
			int num = 0;
			scanf("%d", &num);
			push(stack, num);
		}
		else if (strcmp(str, "pop") == 0)
		{
			if (empty(stack) == 1)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", pop(stack));
			}
		}
		else if (strcmp(str, "size") == 0)
		{
			printf("%d\n", size(stack));
		}
		else if (strcmp(str, "empty") == 0)
		{
			printf("%d\n", empty(stack));
		}
		else if (strcmp(str, "front") == 0)
		{
			if (empty(stack) == 1)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", front(stack));
			}
		}
		else if (strcmp(str, "back") == 0)
		{
			if(empty(stack) == 1)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", back(stack));
			}
		}
	}
}
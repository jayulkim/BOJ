#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[2000005] = { 0, };
int headdown = 100000;
int headup = 99999;

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

void push_back(int* stack, int num)
{
	stack[++headup] = num;
}

void push_front(int* stack, int num)
{
	stack[--headdown] = num;
}

int pop_front(int* stack)
{
	return stack[headdown++];
}
int pop_back(int* stack)
{
	return stack[headup--];
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
		char str[20];
		scanf("%s", str);
		if (strcmp(str, "push_front") == 0)
		{
			int num = 0;
			scanf("%d", &num);
			push_front(stack, num);
		}
		else if (strcmp(str, "push_back") == 0)
		{
			int num = 0;
			scanf("%d", &num);
			push_back(stack, num);
		}
		else if (strcmp(str, "pop_front") == 0)
		{
			if (empty(stack) == 1)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", pop_front(stack));
			}
		}
		else if (strcmp(str, "pop_back") == 0)
		{
			if (empty(stack) == 1)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", pop_back(stack));
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
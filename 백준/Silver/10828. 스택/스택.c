#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[10005] = { 0, };
int head = -1;

int empty(int* stack)
{
	if (head == -1)
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
	stack[++head] = num;
}

int pop(int* stack)
{
	return stack[head--];
}

int size(int* stack)
{
	return head + 1;
}

int top(int* stack)
{
	return stack[head];
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
		else if (strcmp(str, "top") == 0)
		{
			if (empty(stack) == 1)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", top(stack));
			}
		}

	}
	


}
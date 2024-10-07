#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>


int stack[100001];

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

void push(int* stack, int num1)
{
	stack[++head] = num1;
}

int pop(int* stack)
{
	return stack[head--];
}

int top(int* stack)
{
	return stack[head];
}

int main(void)
{
	int num2 = 0;
	scanf("%d", &num2);

	for (int i = 0; i < num2; i++)
	{
		int num1 = 0;
		scanf("%d", &num1);
		
		if (num1 != 0)
		{
			push(stack, num1);
		}
		else if (num1 == 0 && empty(stack) == 0)
		{
			pop(stack);
		}
		
	}
	int result = 0;
	for (int i = 0; i <= head; i++)
	{
		if (stack[i] != 0)
		{
			result += stack[i];
		}
	}
	printf("%d\n", result);
}

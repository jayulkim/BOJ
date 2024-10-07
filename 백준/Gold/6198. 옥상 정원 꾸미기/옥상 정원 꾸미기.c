#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[100005] = { 0, };

int stack[100005] = { 0, };
long long int head = -1;

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
		scanf("%d", &ary[i]);
	}
	
	long long int count = 0;
	
	for (int i = 0; i < num1; i++)
	{
		if (empty(stack) == 1)
		{
			push(stack, ary[i]);
		}
		else
		{
			if (top(stack) > ary[i])
			{
				push(stack, ary[i]);
			}
			else
			{
				while (top(stack) <= ary[i] && empty(stack) == 0)
				{
					pop(stack);
				}
				push(stack, ary[i]);
			}
		}
		
		count += head;
	}
	printf("%lld", count);
}
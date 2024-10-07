#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[1000005] = { 0, };

int stack[1000005] = { 0, };
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

int top(int* stack)
{
	return stack[head];
}

int result[1000005] = { 0, };

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
	}
	
	int index = 0;
	result[index] = -1;
	index++;
	push(stack, ary[num1 - 1]);
	for (int i = num1 - 2; i >= 0; i--)
	{
		if (empty(stack) == 1)
		{
			result[index] = -1;
			index++;
		}
		else
		{
			if (ary[i] < top(stack))
			{
				result[index] = top(stack);
				index++;
				push(stack, ary[i]);
			}
			else
			{
				while (ary[i] >= top(stack) && empty(stack) == 0)
				{
					pop(stack);
				}
				if (empty(stack) == 1)
				{
					result[index] = -1;
					index++;
				}
				else
				{
					result[index] = top(stack);
					index++;
				}
				push(stack, ary[i]);
			}
		}
	}
	for (int i = index - 1; i >= 0; i--)
	{
		printf("%d ", result[i]);
	}
	
}
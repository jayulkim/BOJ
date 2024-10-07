#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[1005] = { 0, };
int stack[1005] = { 0, };
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

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
	}
	int count = 1;
	
	int index = 0;
	while (index <= num1)
	{
		if (top(stack) != count || empty(stack) == 1)
		{
			push(stack, ary[index]);
			index++;
		}
		else if (top(stack) == count)
		{
			pop(stack);
			count++;
		}
		if (head >= 1)
		{
			if (top(stack) > stack[head - 1])
			{
				printf("Sad\n");
				return 0;
			}
		}
	}	
	printf("Nice\n");
}



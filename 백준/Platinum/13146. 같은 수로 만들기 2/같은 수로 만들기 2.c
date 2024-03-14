#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int ary[1000005] = { 0, };
long long int stack[1000005];
int head = -1;

int empty(long long int* stack)
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

void push(long long int* stack, long long int num)
{
	stack[++head] = num;
}

long long int pop(long long int* stack)
{
	return stack[head--];
}

long long int top(long long int* stack)
{
	return stack[head];
}

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	long long int max = 0;
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
		if (max < ary[i])
		{
			max = ary[i];
		}
	}
	long long int count = 0;
	push(stack, ary[0]);
	for (int i = 1; i < num1; i++)
	{	
		if (top(stack) <= ary[i])
		{
			count += (ary[i] - top(stack));
			pop(stack);
		}
		else
		{
			pop(stack);
		}
		push(stack, ary[i]);
	}

	for (int i = 0; i <= head; i++)
	{
		count += (max - stack[i]);
	}
	
	printf("%lld", count);
}
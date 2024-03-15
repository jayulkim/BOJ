#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int ary[500005] = { 0, };
long long int stack[500005];
int head = -1;

typedef struct info
{
	long long int damage;
	int index;
}info;

info stack1[500005];
int head1 = -1;

int empty1(info *stack1)
{
	if (head1 == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
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
void push1(info* stack1, long long int num, int index)
{
	stack1[++head1].damage = num;
	stack1[head1].index = index;
}

long long int pop(long long int* stack)
{
	return stack[head--];
}
info pop1(info* stack1)
{
	return stack1[head1--];
}

long long int top(long long int* stack)
{
	return stack[head];
}
long long int top1(info* stack1)
{
	return stack1[head1].damage;
}
long long int Max(long long int num4, long long int num5)
{
	if (num4 >= num5)
	{
		return num4;
	}
	else
	{
		return num5;
	}
}

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	long long int count = 0;
	for (int i = 0; i < num1; i++)
	{
		long long int num2 = 0;
		long long int num3 = 0;
		scanf("%lld %lld",&num2, &num3);

		if (num2 == 1)
		{
			push(stack, num3);
		}
		else if (num2 == 2)
		{
			if (empty(stack) == 0)
			{
				if (empty1(stack1) == 1)
				{
					push1(stack1, Max(top(stack) - num3, 0), i);
				}
				else
				{
					while (top1(stack1) >= Max(top(stack) - num3, 0) && empty1(stack1) == 0)
					{
						ary[pop1(stack1).index]++;
					}
					push1(stack1, Max(top(stack) - num3, 0), i);
				}
			}
			push(stack, Max(top(stack) - num3, 0));
		}
	}
	for (int i = 0; i <= head; i++)
	{
		//printf("%lld ", stack[i]);
	}
	
	if (empty1(stack1) == 0)
	{
		int index1 = 0;
		for (int i = 0; i <= head1; i++)
		{
		//	printf("%lld %lld\n", stack1[i].damage, stack1[i].index);
			for (int j = index1; j < stack1[i].index; j++)
			{
				if (ary[j] == 0)
				{
					if (stack[j] < stack1[i].damage)
					{
						count += stack[j];
					}
					else
					{
						count += stack1[i].damage;
					}
				}
				
			}
			index1 = stack1[i].index + 1;
		}
		for (int i = stack1[head1].index + 1; i <= head; i++)
		{
			count += stack[i];
		}
	}
	else
	{
		for (int i = 0; i <= head; i++)
		{
			count += stack[i];
		}
	}
	
	printf("%lld", count);
}
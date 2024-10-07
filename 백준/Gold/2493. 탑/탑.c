#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct info
{
	int number;
	int index;
}info;
info ary[500005];

info stack[500005];
int head = -1;

int empty(info* stack)
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

void push(info* stack, int num, int index)
{
	stack[++head].number = num;
	stack[head].index = index;
}

info pop(info* stack)
{
	return stack[head--];
}

info top(info* stack)
{
	return stack[head];
}

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i].number);
		ary[i].index = i + 1;
	}

	if (empty(stack) == 1)
	{
		printf("0 ");
		push(stack, ary[0].number, ary[0].index);
	}
	for (int i = 1; i < num1; i++)
	{
		if (empty(stack) == 1)
		{
			printf("0 ");
			push(stack, ary[i].number, ary[i].index);
		}
		else
		{
			if (top(stack).number < ary[i].number)
			{
				while (ary[i].number > top(stack).number && empty(stack) == 0)
				{
					pop(stack);
				}
				
				if (empty(stack) == 1)
				{
					printf("0 ");	
				}
				else
				{
					printf("%d ", top(stack).index);
				}
				push(stack, ary[i].number, ary[i].index);
			}
			else
			{
				printf("%d ", top(stack).index);
				push(stack, ary[i].number, ary[i].index);
			}
		}
	}
}
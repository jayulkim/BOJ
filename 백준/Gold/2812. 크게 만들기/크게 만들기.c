#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[500005];

int stack[500005] = { 0, };
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
	//printf("%d %d", '0', '9');
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	scanf("%s", str);


	push(stack, str[0]);
	for (int i = 1; i < num1; i++)
	{
		if (empty(stack) == 1)
		{
			push(stack, str[i]);
		}
		else
		{
			if (top(stack) < str[i])
			{
				if (num2 != 0)
				{
					while (top(stack) < str[i] && num2 != 0 && empty(stack) == 0)
					{
						pop(stack);
						num2--;
					}
					push(stack, str[i]);
				}
				else
				{
					push(stack, str[i]);
				}	
			}
			else
			{
				push(stack, str[i]);
			}
		}
	}
	if (num2 != 0)
	{
		for (int i = num2; i > 0; i--)
		{
			if (empty(stack) == 0)
			{
				pop(stack);
			}
			else
			{
				break;
			}
		}
	}
	if (empty(stack) == 0)
	{
		for (int i = 0; i <= head; i++)
		{
			printf("%d", stack[i] - 48);
		}
	}
}



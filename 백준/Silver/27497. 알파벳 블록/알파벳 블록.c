#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

char deque[5000005] = { 0, };
int headdown = 2500000; 
int headup = 2499999;

int empty(char* deque)
{
	if (headdown - 1 == headup)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void pushup(char* deque, char str)
{
	deque[++headup] = str;
}

void pushdown(char* deque, char str)
{
	deque[--headdown] = str;
}

char popup(char* deque)
{
	return deque[headup--];
}

char popdown(char* deque)
{
	return deque[headdown++];
}

int stack[1000005] = { 0, };
int head = -1;

int emptystack(int* stack)
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
	int count = 0;
	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		scanf("%d", &num2);
		if (num2 == 1)
		{
			char str1;
			scanf(" %c", &str1);
			pushup(deque, str1);
			push(stack, 1);
		}
		else if (num2 == 2)
		{
			char str1;
			scanf(" %c", &str1);
			pushdown(deque, str1);
			push(stack, 0);
		}
		else if (num2 == 3)
		{
			if (top(stack) == 1)
			{
				if (empty(deque) == 0)
				{
					popup(deque);
				}
				pop(stack);
			}
			else if (top(stack) == 0)
			{
				if (empty(deque) == 0)
				{
					popdown(deque);
				}
				pop(stack);
			}
		}
	}
	if (empty(deque) == 1)
	{
		printf("0\n");
	}
	else
	{
		for (int i = headdown; i <= headup; i++)
		{
			printf("%c", deque[i]);
		}
	}
}
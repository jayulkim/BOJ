#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[1000];

int head = -1;

int empty(char* stack)
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


void push(char* stack, char str)
{
	stack[++head] = str;
}

char pop(char* stack)
{
	return stack[head--];
}

char top(char* stack)
{
	return stack[head];
}

int main(void)
{
	while (1)
	{
		char str[1000];
		gets(str);
		if (str[0] == '.')
		{
			break;
		}

		int num1 = strlen(str);

		int count = 0;
		for (int i = 0; i < num1; i++)
		{
			if (str[i] == '(')
			{
				push(stack, '(');
			}
			else if (str[i] == ')')
			{
				if (empty(stack) == 1 || top(stack) == '[')
				{
					count++;
					break;
				}
				else
				{
					pop(stack);
				}
			}

			if (str[i] == '[')
			{
				push(stack, '[');
			}
			else if (str[i] == ']')
			{
				if (empty(stack) == 1 || top(stack) == '(')
				{
					count++;
					break;
				}
				else
				{
					pop(stack);
				}
			}

		}
		if (count == 0)
		{
			if (empty(stack) == 1)
			{
				printf("yes\n");
			}
			else
			{
				printf("no\n");
			}
		}
		else
		{
			printf("no\n");
		}
		head = -1;

	}
}
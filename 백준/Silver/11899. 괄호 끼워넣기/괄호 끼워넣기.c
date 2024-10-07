#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[55];
char stack[55];
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

char pop(char* stack)
{
	return stack[head--];
}

void push(char* stack, char str)
{
	stack[++head] = str;
}

char top(char* stack)
{
	return stack[head];
}

int main(void)
{
	scanf("%s", str);

	int num1 = strlen(str);
	
	int count = 0;
	for (int i = 0; i < num1; i++)
	{
		if (str[i] == '(')
		{
			push(stack, str[i]);
		}
		else if (str[i] == ')')
		{
			if (empty(stack) == 1)
			{
				count++;
			}
			else if (top(stack) == '(')
			{
				pop(stack);
			}
		}
	}
	printf("%d\n", count + head + 1);
}


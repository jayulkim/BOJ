#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

char stack[3000];

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
	int count2 = 1;
	while (1)
	{
		char str[3000];

		scanf("%s", str);

		
		int num1 = strlen(str);
		
		int count = 0;
		int count1 = 0;
		for (int i = 0; i < num1; i++)
		{
			if (str[i] == '-')
			{
				count1++;
				break;
			}

			if (str[i] == '{')
			{
				push(stack, '{');

			}
			else if (str[i] == '}')
			{
				if (empty(stack) == 0)
				{
					pop(stack);
				}
				else if (empty(stack) == 1)
				{
					push(stack,'{');
					count++;
				}
			}
		}
		if (count1 != 0)
		{
			break;
		}

		printf("%d. %d\n", count2, count + (head + 1) / 2);

		
		head = -1;
		count2++;
	}



}
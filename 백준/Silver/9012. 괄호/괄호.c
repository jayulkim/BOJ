#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[55] = { 0, };
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

int pop(int* stack)
{
	return stack[head--];
}
void push(int* stack, int num)
{
	stack[++head] = num;
}


int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		char str[55];
		scanf("%s", str);
		int count = 0;
		int num2 = strlen(str);
		for (int j = 0; j <= num2; j++)
		{
			if (str[j] == '(')
			{
				push(stack, '(');
			}
			else if (str[j] == ')')
			{
				if (j == 0)
				{
					printf("NO\n");
					count++;
					break;
				}
				else
				{
					if (empty(stack) == 0)
					{
						pop(stack);
					}
					else
					{
						count++;
						printf("NO\n");
						break;
					}
				}
			}
		}
		if (count == 0)
		{
			if (empty(stack) == 1)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
		head = -1;
	}
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

char str[1000005];
char stack[1000005];
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
char str1[1000005];

int main(void)
{
	scanf("%s", str);
	int num1 = strlen(str);
	for (int i = 0; i < num1; i++)
	{
		push(stack, str[i]);
		if (stack[head] == 'P' && stack[head - 1] == 'A' && stack[head - 2] == 'P' && stack[head - 3] == 'P')
		{

			pop(stack);
			pop(stack);
			pop(stack);
			pop(stack);
			push(stack, 'P');
			for (int j = 0; j <= head; j++)
			{
				//	printf("%c", stack[j]);
			}
			//printf("\n");
		}
		for (int j = 0; j <= head; j++)
		{
			//  printf("%c", stack[j]);
		}
		//	printf("\n");
		//	printf("%d\n", head);
	}
	int index = 0;
	for (int i = 0; i <= head; i++)
	{
		str1[index] = stack[i];
		index++;
	}
	//printf("%d\n", head);
	if (strcmp(str1, "PPAP") == 0 || (head == 0) && stack[head] == 'P')
	{
		printf("PPAP");
	}
	else
	{
		printf("NP");
	}
}
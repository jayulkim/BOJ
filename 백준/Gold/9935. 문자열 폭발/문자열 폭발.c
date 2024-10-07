#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>


char str[1000005];
char str1[40];
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

char top(char* stack)
{
	return stack[head];
}


int main(void)
{
	scanf("%s", str);
	scanf("%s", str1);

	int num1 = strlen(str);
	int num2 = strlen(str1);

	for (int i = 0; i <= num1; i++)
	{
		
		push(stack, str[i]);
		if (strncmp(stack + (head - num2 + 1), str1, num2) == 0)
		{		
			for (int i = 0; i < num2; i++)
			{
				pop(stack);
			}
			//printf("%s\n", stack);
		}
	}
//	printf("%d\n", head);

	if (head == 0)
	{
		printf("FRULA\n");
	}
	else
	{
		printf("%s\n", stack);
	}
	

}
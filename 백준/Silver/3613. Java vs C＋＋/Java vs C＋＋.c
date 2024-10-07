#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <memory.h>

char str[105];
char stack[105];
int head = -1;

void push(char* stack, char str)
{
	stack[++head] = str;
}



int main(void)
{
	//printf("%c %c", 97, 65);
	scanf("%s", str);
	int num1 = strlen(str);

	int count = 0;
	for (int i = 0; i <= num1; i++)
	{
		if (str[i] == '_')
		{
			if (i == num1 - 1 || i == 0)
			{
				printf("Error!\n");
				return 0;
			}
			count++;
		}
		if (str[i] == '_' && str[i + 1] == '_')
		{
			printf("Error!\n");
			return 0;
		}

	}
	if (count != 0)
	{
		for (int i = 0; i <= num1; i++)
		{
			if (str[i] == 'A' || str[i] == 'B' || str[i] == 'C' || str[i] == 'D' || str[i] == 'E' || str[i] == 'F' || str[i] == 'G' || str[i] == 'H' || str[i] == 'I' || str[i] == 'J' || str[i] == 'K' || str[i] == 'L' || str[i] == 'M' || str[i] == 'N' || str[i] == 'O' || str[i] == 'P' || str[i] == 'Q' || str[i] == 'R' || str[i] == 'S' || str[i] == 'T' || str[i] == 'U' || str[i] == 'V' || str[i] == 'W' || str[i] == 'X' || str[i] == 'Y' || str[i] == 'Z')
			{
				printf("Error!\n");
				return 0;
			}
		}
		for (int i = 0; i <= num1; i++)
		{
			if (str[i] == '_')
			{
				push(stack, str[i + 1] - 32);
				i++;
			}
			else
			{
				push(stack, str[i]);
			}
		}
		printf("%s\n", stack);

	}
	else
	{
		if (str[0] == 'A' || str[0] == 'B' || str[0] == 'C' || str[0] == 'D' || str[0] == 'E' || str[0] == 'F' || str[0] == 'G' || str[0] == 'H' || str[0] == 'I' || str[0] == 'J' || str[0] == 'K' || str[0] == 'L' || str[0] == 'M' || str[0] == 'N' || str[0] == 'O' || str[0] == 'P' || str[0] == 'Q' || str[0] == 'R' || str[0] == 'S' || str[0] == 'T' || str[0] == 'U' || str[0] == 'V' || str[0] == 'W' || str[0] == 'X' || str[0] == 'Y' || str[0] == 'Z')
		{
			printf("Error!\n");
			return 0;
		}
		else
		{
			for (int i = 0; i <= num1; i++)
			{
				if (str[i] == 'A' || str[i] == 'B' || str[i] == 'C' || str[i] == 'D' || str[i] == 'E' || str[i] == 'F' || str[i] == 'G' || str[i] == 'H' || str[i] == 'I' || str[i] == 'J' || str[i] == 'K' || str[i] == 'L' || str[i] == 'M' || str[i] == 'N' || str[i] == 'O' || str[i] == 'P' || str[i] == 'Q' || str[i] == 'R' || str[i] == 'S' || str[i] == 'T' || str[i] == 'U' || str[i] == 'V' || str[i] == 'W' || str[i] == 'X' || str[i] == 'Y' || str[i] == 'Z')
				{
					push(stack, '_');
					push(stack, str[i] + 32);
				}
				else
				{
					push(stack, str[i]);
				}
			}
		}
		printf("%s", stack);
	}
}
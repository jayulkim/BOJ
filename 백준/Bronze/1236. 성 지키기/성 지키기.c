#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

char str[60][60];

int main(void)
{
	int num1 = 0;
	int num2 = 0;

	scanf("%d %d", &num1, &num2);

	for (int i = 0; i < num1; i++)
	{
		scanf("%s", str[i]);
	}

	int countcol = 0;
	int countrow = 0;
	for (int i = 0; i < num1; i++)
	{
		int count = 0;
		for (int j = 0; j < num2; j++)
		{
			if (str[i][j] == 'X')
			{
				count++;
				break;
			}
		}
		if (count == 0)
		{
			countcol++;
		}
	}
	for (int i = 0; i < num2; i++)
	{
		int count = 0;
		for (int j = 0; j < num1; j++)
		{
			if (str[j][i] == 'X')
			{
				count++;
				break;
			}
		}
		if (count == 0)
		{
			countrow++;
		}
	}
	if (countcol >= countrow)
	{
		printf("%d\n", countcol);
	}
	else
	{
		printf("%d\n", countrow);
	}

}




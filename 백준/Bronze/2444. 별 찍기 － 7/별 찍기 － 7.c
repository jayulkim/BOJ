#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	for (int i = 1; i < num1; i++)
	{
		for (int j = num1 - i; j > 0; j--)
		{
			printf(" ");
		}
		for (int k = 0; k < 2 * i - 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}

	for (int i = num1; i > 0; i--)
	{
		for (int j = 0; j < num1 - i; j++)
		{
			printf(" ");
		}
		for (int k = 2 * i - 1; k > 0; k--)
		{
			printf("*");
		}
		printf("\n");
	}

}
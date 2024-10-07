#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int num1 = 0;

	scanf("%d", &num1);

	for (int i = num1 - 1; i >= 1; i--)
	{
		for (int j = num1 - 1; j >= i; j--)
		{
			printf("*");
		}
		printf("\n");
	}
	for (int i = 0; i < num1; i++)
	{
		printf("*");
	}
	printf("\n");
	for (int i = 1; i <= num1- 1; i++)
	{
		for (int j = num1 - 1; j >= i; j--)
		{
			printf("*");
		}
		printf("\n");
	}
}
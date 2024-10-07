#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num1 = 0;

	scanf("%d", &num1);

	for (int i = 1; i <= num1; i++)
	{
		for (int j = 1; j < i; j++)
		{
			printf(" ");
		}
		for (int j = 1; j <= 2 * (num1 - i) + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
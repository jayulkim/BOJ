#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>



int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	for (int i = 0; i < num1 - 1; i++)
	{
		for (int k = 0; k < i; k++)
		{
			printf(" ");
		}
		for (int j = 2 * (num1 - i) - 1; j >= 1; j--)
		{
			printf("*");
		}
		printf("\n");
		
	}


	for (int i = num1 - 1; i >= 0; i--)
	{
		for (int k = i; k >= 1; k--)
		{
			printf(" ");
		}
		for (int j = 0; j < 2 * (num1 - i) - 1; j++)
		{
			printf("*");
		}
		printf("\n");

	}
}
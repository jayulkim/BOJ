#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
	int num1 = 0;

	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		for (int j = i; j <= num1 - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}


   
}
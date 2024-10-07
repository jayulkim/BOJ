#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 0;

	scanf("%d", &num1);

	for (int j = 0; j < num1; j++)
	{
		for (int i = 0; i < num1 * 5; i++)
		{
			printf("@");
		}
		printf("\n");
	}

	for (int j = 0; j < num1 * 5 - num1; j++)
	{	
		for (int i = 0; i < num1; i++)
		{
			printf("@");
		}
		printf("\n");
	}
		
		
	

}
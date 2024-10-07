#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	while (1)
	{
		int num2 = 0;
		scanf("%d", &num2);
		if (num2 == 0)
		{
			break;
		}
		if (num2 % num1 == 0)
		{
			printf("%d is a multiple of %d.\n", num2, num1);
		}
		else
		{
			printf("%d is NOT a multiple of %d.\n", num2, num1);
		}
	}
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	if (num1 == 3)
	{
		printf("0\n");
	}
	else if (num1 == 6)
	{
		printf("0\n");
	}
	else
	{
		int num2 = num1 / 3 - 3;

		long long int num3 = 1;

		for (int i = 0; i < 2; i++)
		{
			num3 *= 2 + num2 - i;
		}
		printf("%lld\n", num3 / 2);
		
	}
	
}

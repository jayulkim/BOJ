#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
	int num1 = 0;
	int num2 = 0;

	scanf("%d", &num1);

	while (1)
	{
		num2++;

		if (num1 == ((num2 & 10000000) / 1000000) + ((num2 % 1000000) / 100000) + ((num2 % 100000) / 10000) + ((num2 % 10000) / 1000) + ((num2 % 1000) / 100) + ((num2  % 100) / 10) + (num2 % 10) + num2 && num1 != 1000000)
		{
			printf("%d", num2);
			break;
			
		}
		if (num2 > num1)
		{
			printf("0");
			break;
		}
		if (num1 == 1000000)
		{
			printf("0");
			break;
		}
		
	}
	
}
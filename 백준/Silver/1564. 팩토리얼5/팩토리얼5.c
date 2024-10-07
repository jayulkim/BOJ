#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	int num1 = 0;

	scanf("%d", &num1);

	if (num1 == 1)
	{
		printf("%d\n", 1);
	}
	else
	{

		long long int num2 = 1;


		for (long long int i = 2; i <= num1; i++)
		{
			long long int num3 = i;
			
			num2 = num2 * num3;
			
			
			
			while (num2 % 10 == 0)
			{
				num2 /= 10;
			}
			num2 %= 1000000000000;
			
		}

		if (num2 % 100000 < 10000 && num2 % 100000 >= 1000)
		{
			printf("0%lld\n", num2 % 100000);
		}
		else if (num2 % 100000 < 1000 && num2 % 100000 >= 100)
		{
			printf("00%lld\n", num2 % 100000);
		}
		else if (num2 % 100000 < 100 && num2 % 100000 >= 10)
		{
			printf("000%lld\n", num2 % 100000);
		}
		else if (num2 % 100000 < 10 && num2 % 100000 >= 0)
		{
			printf("0000%lld\n", num2 % 100000);
		}
		else if (num2 % 100000 >= 10000)
		{
			printf("%lld\n", num2 % 100000);
		}
		

	}


}
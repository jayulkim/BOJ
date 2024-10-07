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
			
			
			num2 %= 100000000;
			while (num2 % 10 == 0)
			{
				num2 /= 10;
			}
			
		}
		printf("%lld\n", num2 % 10);

	}


}
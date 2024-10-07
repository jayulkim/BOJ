#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	int num1 = 0;

	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;

		scanf("%d", &num2);

		long long int result = 1;
		for (int i = 2; i <= num2; i++)
		{
			result *= i;
			result %= 10000000;
			while (result % 10 == 0)
			{
				result /= 10;
			}
		}
		printf("%lld\n", result % 10);
	}


}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ary[100000005] = { 0, };

int main(void)
{
	for (int i = 2; i * i <= 100000000; i++)
	{
		if (ary[i] == '\0')
		{
			for (int j = i * i; j <= 100000000; j += i)
			{
				ary[j] = '1';
			}
		}
	}

	//printf("%d\n", index);
	long long int num1 = 0;
	long long int result = 1;
	scanf("%lld", &num1);
	for (long long int i = 2; i <= num1; i++)
	{
		if (ary[i] == '\0')
		{
			long long int temp = 1;
			while (temp * i <= num1)
			{
				temp *= i;
			}
			result *= (temp % 4294967296);
			result %= 4294967296;
		}
	}

	printf("%lld", result % 4294967296);
}

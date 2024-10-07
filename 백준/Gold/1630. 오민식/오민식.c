#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int ary[1000005] = { 0, };

long long int prime[100005] = { 0, };
long long int max[1000005] = {0,};
long long int max1[1000005] = { 0, };
int main(void)
{
	long long int result = 1;
	long long int num1 = 0;
	scanf("%lld", &num1);
	long long int index = 0;
	for (long long int i = 2; i <= num1; i++)
	{
		if (ary[i] == 0)
		{	
			result *= (i % 987654321);
			result %= 987654321;
			for (long long int j = 2 * i; j <= num1; j += i)
			{
				ary[j] = 1;
				long long int num2 = j;
				while (num2 > 1)
				{
					if (num2 % i == 0)
					{
						num2 /= i;
						index++;
					}
					else
					{
						break;
					}
				}
				if (max[i] < index)
				{
					max[i] = index;
				}
				index = 0;
			}
		}
	}

	for (long long int i = 2; i <= num1; i++)
	{
		if (max[i] - 1 > 0)
		{
			for (long long int j = 0; j < max[i] - 1; j++)
			{
				result *= (i % 987654321);
				result %= 987654321;
			}
		}
	}
	printf("%lld", result % 987654321);
}
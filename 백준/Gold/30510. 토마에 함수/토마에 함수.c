#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long int sum[100001][330] = { 0, };

int ary[330] = { 0, };
long long int prime[330] = { 0, };
long long int ary1[100001] = { 0, };
long long int result[100001] = { 0, };

long long int oilerpi(long long int (*sum)[330], int num1)
{
	long long int result = 1LL;
	for (long long int i = 2; i <= 317; i++)
	{
		long long int count = 1LL;
		if (sum[num1][i] != 0)
		{
			count *= (i - 1LL);
			if (sum[num1][i] > 1)
			{
				for (long long int j = 0; j < sum[num1][i] - 1; j++)
				{
					count *= i;
				}
			}
		}
		result *= count;
	}
	if (sum[num1][320] != 0)
	{
		result *= (sum[num1][320] - 1LL);
	}
	return result;
}

int main(void)
{
	for (int i = 2; i * i <= 317; i++)
	{
		if (ary[i] == 0)
		{
			for (int j = i * i; j <= 317; j += i)
			{
				ary[j] = 1;
			}
		}
	}
	int index = 0;
	for (long long int i = 2; i <= 317; i++)
	{
		if (ary[i] == 0)
		{
			prime[index] = i;
			index++;
		}
	}
	for (long long int i = 2; i <= 100000; i++)
	{
		long long int num1 = i;
		int index1 = 0;
		while (num1 > 1)
		{
			if (num1 % prime[index1] == 0)
			{
				sum[i][prime[index1]]++;
				num1 /= prime[index1];
			}
			else
			{
				index1++;
			}
			if (prime[index1] == 0)
			{
				sum[i][320] = num1;
				break;
			}
		}
	}
	ary1[1] = 2;
	for (int i = 2; i <= 100000; i++)
	{
		ary1[i] = oilerpi(sum, i);
	}
	result[1] = ary1[1];
	for (int i = 2; i <= 100000; i++)
	{
		result[i] = result[i - 1] + ary1[i];
	}
	int up = 0;
	int down = 0;
	scanf("%d %d", &up, &down);
	int number = down / up;
	printf("%lld", result[number]);
}
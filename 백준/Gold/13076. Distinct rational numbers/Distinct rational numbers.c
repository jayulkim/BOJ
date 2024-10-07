#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int sum[10001][105] = { 0, };

int ary[101] = { 0, };
int prime[101] = { 0, };
int ary1[10001] = { 0, };
int result[10001] = { 0, };

int oilerpi(int (*sum)[105], int num1)
{
	int result = 1;
	for (int i = 2; i <= 100; i++)
	{
		int count = 1;
		if (sum[num1][i] != 0)
		{
			count *= (i - 1);
			if (sum[num1][i] > 1)
			{
				for (int j = 0; j < sum[num1][i] - 1; j++)
				{
					count *= i;
				}
			}
		}
		result *= count;
	}
	if (sum[num1][101] != 0)
	{
		result *= (sum[num1][101] - 1);
	}
	return result;
}

int main(void)
{
	for (int i = 2; i * i <= 100; i++)
	{
		if (ary[i] == 0)
		{
			for (int j = i * i; j <= 100; j += i)
			{
				ary[j] = 1;
			}
		}
	}
	int index = 0;
	for (long long int i = 2; i <= 100; i++)
	{
		if (ary[i] == 0)
		{
			prime[index] = i;
			index++;
		}
	}
	for (int i = 2; i <= 10000; i++)
	{
		int num1 = i;
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
				sum[i][101] = num1;
				break;
			}
		}
	}
	for (int i = 2; i <= 10000; i++)
	{
		ary1[i] = oilerpi(sum, i);
	}
	result[2] = ary1[2];
	for (int i = 3; i <= 10000; i++)
	{
		result[i] = result[i - 1] + ary1[i];
	}
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int num2 = 0;
		scanf("%d", &num2);
		printf("%d\n", result[num2] + 2);
	}
}
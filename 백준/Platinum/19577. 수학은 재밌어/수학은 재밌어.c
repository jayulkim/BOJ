#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int sum[100001][1005] = { 0, };

int ary[1001] = { 0, };
int prime[1001] = { 0, };
int ary1[100001] = { 0, };
int result[100001] = { 0, };

int oilerpi(int (*sum)[1005], int num1)
{
	int result = 1;
	for (int i = 2; i <= 1000; i++)
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
	if (sum[num1][1001] != 0)
	{
		result *= (sum[num1][1001] - 1);
	}
	return result;
}

int main(void)
{
	for (int i = 2; i * i <= 1000; i++)
	{
		if (ary[i] == 0)
		{
			for (int j = i * i; j <= 1000; j += i)
			{
				ary[j] = 1;
			}
		}
	}
	int index = 0;
	for (long long int i = 2; i <= 1000; i++)
	{
		if (ary[i] == 0)
		{
			prime[index] = i;
			index++;
		}
	}
	for (int i = 2; i <= 100000; i++)
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
				sum[i][1001] = num1;
				break;
			}
		}
	}
	for (int i = 2; i <= 100000; i++)
	{
		ary1[i] = oilerpi(sum, i);
	}
	int num = 0;
	scanf("%d", &num);
	if (num == 1)
	{
		printf("1");
		return 0;
	}
	for (int i = 2; i <= 100000; i++)
	{
		if (i * ary1[i] == num)
		{
			printf("%d", i);
			return 0;
		}
	}
	printf("-1");
}
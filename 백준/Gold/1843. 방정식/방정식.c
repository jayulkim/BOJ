#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int ary[500005] = { 0, };
long long int sum[500005] = { 0, };

int ary1[500005] = { 0, };
int ary2[50005] = { 0, };

int prime[500005] = { 0, };

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	ary[1] = 0;
	ary[2] = 0;
	ary[3] = 1;
	ary[4] = 1;
	ary[5] = 2;
	ary[6] = 2;
	for (int i = 7; i <= 500000; i++)
	{
		if (i % 2 == 1)
		{
			ary[i] = i / 2;
		}
		else
		{
			ary[i] = i / 2 - 1;
		}
	}

	sum[1] = ary[1];
	for (int i = 2; i <= 500000; i++)
	{
		sum[i] = sum[i - 1] + ary[i];
	}

	
	printf("%lld\n", sum[num1]);
	for (int i = 1; i * i <= num1; i++)
	{
		if (num1 % i == 0)
		{
			ary1[i] = 1;
			ary1[num1 / i] = 1;
		}
	}
	int index = 0;
	for (int i = 1; i <= 500000; i++)
	{
		if (ary1[i] == 1)
		{
			ary2[index] = i;
			index++;
		}
	}
	long long int count = 0;
	for (int i = 0; i < index; i++)
	{
		for (int j = i; j < index; j++)
		{
			if (ary1[ary2[i] + ary2[j]] == 1 && ary2[i] + ary2[j] <= 500000LL)
			{
				count++;
			}
		}
	}
	printf("%lld\n", count);

	for (int i = 2; i * i <= 500000; i++)
	{
		if (prime[i] == 0)
		{
			for (int j = i * i; j <= 500000; j += i)
			{
				prime[j] = 1;
			}
		}
	}
	long long int count1 = 0;
	for (int i = 2; i <= num1 - 2; i++)
	{
		if (prime[i] == 0)
		{
			if (prime[i + 2] == 0)
			{
				count1++;
			}
		}
	}
	printf("%lld", count1);
}

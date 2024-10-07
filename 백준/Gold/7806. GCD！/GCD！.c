#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int ary[40005] = { 0, };
long long int prime[8000] = { 0, };

long long int k[40005] = { 0, };
long long int n[40005] = { 0, };

long long int Min(long long int num1, long long int num2)
{
	if (num2 > num1)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}
int main(void)
{
	ary[1] = 1;
	ary[0] = 1;
	for (int i = 2; i * i <= 40000; i++)
	{
		if (ary[i] == 0)
		{
			for (int j = i * i; j <= 40000; j += i)
			{
				ary[j] = 1;
			}
		}
	}
	int index = 0;
	for (long long int i = 2; i <= 40000; i++)
	{
		if (ary[i] == 0)
		{
			prime[index] = i;
			index++;
		}
	}
	long long int num1 = 0;
	long long int num2 = 0;
	while (scanf("%lld %lld", &num1, &num2) != EOF)
	{
		if (num1 == 1)
		{
			printf("1\n");
		}
		else
		{
			long long int num3 = num2;
			long long int result = 1;
			int count1 = 0;
			long long int primek = 0;
			int index1 = 0;
			while (num3 > 1) 
			{
				if (num3 % prime[index1] == 0)
				{
					k[prime[index1]]++;
					num3 /= prime[index1];
				}
				else
				{
					index1++;
				}
				if (prime[index1] == 0)
				{
					primek = num3;
					count1++;
					break;
				}
			}

			if (count1 != 0)
			{
				if (num1 >= num3) 
				{
					result *= primek;
				}
			}
			for (long long int i = 0; i < index; i++) 
			{
				for (long long int j = prime[i]; j <= num1; j *= prime[i])
				{
					n[prime[i]] += num1 / j;
				}
			}

			for (int i = 0; i < index; i++)
			{
				if (n[prime[i]] != 0 && k[prime[i]] != 0) 
				{
					for (int j = 0; j < Min(n[prime[i]], k[prime[i]]); j++)
					{
						result *= prime[i];
					}
				}
			}
			printf("%lld\n", result);
		}
		memset(k, 0, sizeof(k));
		memset(n, 0, sizeof(n));
	}
}
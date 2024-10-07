#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int ary[100001] = { 0, };
long long int prime[50001] = { 0, };
long long int sum[100001] = { 0, };
int stack[100001] = { 0, };
int head = -1;
void push(int* stack, int num)
{
	stack[++head] = num;
}
long long int oilerpi(long long int prime)
{
	long long int result = 1;
	if (sum[prime] > 1)
	{
		for (int i = 0; i < sum[prime] - 1; i++)
		{
			result *= prime;
		}
	}
	return result * (prime - 1);
}

int main(void)
{
	for (int i = 2; i * i <= 100000; i++)
	{
		if (ary[i] == 0)
		{
			for (int j = i * i; j <= 100000; j += i)
			{
				ary[j] = 1;
			}
		}
	}
	int index = 0;
	for (long long int i = 2; i <= 100000; i++)
	{
		if (ary[i] == 0)
		{
			prime[index] = i;
			index++;
		}
	}
	while (1)
	{
		long long int num1 = 0;
		int index1 = 0;
		long long int sosoo = 0;
		scanf("%lld", &num1);
		if (num1 == 0)
		{
			break;
		}
		if (num1 == 1)
		{
			printf("0\n");
		}
		else
		{
			while (num1 > 1)
			{
				if (num1 % prime[index1] == 0)
				{
					if (sum[prime[index1]] == 0)
					{
						push(stack, prime[index1]);
					}
					sum[prime[index1]]++;
					num1 /= prime[index1];
				}
				else
				{
					index1++;
				}
				if (prime[index1] == 0)
				{
					sosoo = num1;
					break;
				}
			}
			long long int result = 1;
			if (sosoo != 0)
			{
				result *= (sosoo - 1);
			}
			if (head != -1)
			{
				for (int i = 0; i <= head; i++)
				{
					result *= oilerpi(stack[i]);
				}
			}
			printf("%lld\n", result);
		}
		memset(sum, 0, sizeof(sum));
		head = -1;
	}
}
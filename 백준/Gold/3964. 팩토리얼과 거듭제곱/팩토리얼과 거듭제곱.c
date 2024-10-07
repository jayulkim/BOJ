#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

int ary[1000001] = { 0, };
long long int prime[100001] = { 0, };

long long int stack[100001] = { 0, };
int head = -1;
void push(long long int* stack, long long int num)
{
	stack[++head] = num;
}
long long int sum[1000001] = { 0, };

int main(void)
{
	for (int i = 2; i * i <= 1000000; i++)
	{
		if (ary[i] == 0)
		{
			for (int j = i * i; j <= 1000000; j += i)
			{
				ary[j] = 1;
			}
		}
	}
	int index = 0;
	for (long long int i = 2; i <= 1000000; i++)
	{
		if (ary[i] == 0)
		{
			prime[index] = i;
			index++;
		}
	}
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		long long int min = 9223372036854775807LL;
		long long int n = 0;
		long long int k = 0;
		scanf("%lld %lld", &n, &k);
		int index1 = 0;
		long long int primeinsoo = 0;
        long long int result = 0;
		while (k > 1)
		{
			if (k % prime[index1] == 0)
			{
				if (sum[prime[index1]] == 0)
				{
					push(stack, prime[index1]);
				}
				sum[prime[index1]]++;
				k /= prime[index1];
			}
			else
			{
				index1++;
			}
			if (prime[index1] == 0)
			{
				primeinsoo = k;
				break;
			}
		}
		if (primeinsoo != 0 && primeinsoo > n)
		{
			printf("0\n");
		}
		else
		{
			int count = 0;
			if (primeinsoo != 0)
			{
				long long int result1 = 0;
				long long int jj = primeinsoo;
                long long int end1 = log(n) / log(primeinsoo);
				for (long long int j = 0; j < end1; j++)
				{
					result1 += n / jj;
					jj *= primeinsoo;
				}
				if (min > result1)
				{
					min = result1;
				}
			}
			for (int j = 0; j <= head; j++)
			{
                
				if (stack[j] <= n)
				{
					long long int result = 0;
					long long int kk = stack[j];
                    long long int end = log(n) / log(stack[j]);
					for (long long int k = 0; k < end; k++)
					{
						result += n / kk;
						kk *= stack[j];
					}
					if (min > result / sum[stack[j]])
					{
						min = result / sum[stack[j]];
					}
				}
				else
				{
					printf("0\n");
					count++;
					break;
				}
			}	
			if (count == 0)
			{
				printf("%lld\n", min);
			}
		}
		memset(sum, 0, sizeof(sum));
		head = -1;
	}
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prime[10000005] = { 0, };
long long int ary[1000005] = { 0, };
int sum[10000005] = { 0, };
int main(void)
{
	for (int i = 2; i <= 10000000; i++)
	{
		if (prime[i] == 0)
		{
			for (int j = 2 * i; j <= 10000000; j += i)
			{
				prime[j] = 1;
			}
		}
	}
	int index = 0;
	for (long long int i = 2; i <= 10000000; i++)
	{
		if (prime[i] == 0)
		{
			ary[index] = i;
			index++;
		}
	}
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		int count1 = 0;
		int num2 = 0;
		scanf("%d", &num2);
		for (int j = 0; j < num2; j++)
		{
			int num3 = 0;
			scanf("%d", &num3);
			long long int count = 0;
			if (num3 == 1)
			{
				for (int k = 0; k < index; k++)
				{
					sum[ary[k]]++;
				}
			}
			else
			{
				for (int k = 0; k < num3; k++)
				{
					count += ary[k];
				}
				if (count >= 10000000)
				{
					count1++;
					break;
				}
				sum[count]++;
				int k = num3;
				while (k < index && count + (ary[k] - ary[k - num3]) <= 10000000)
				{
					count += (ary[k] - ary[k - num3]);
					sum[count]++;
					k++;
				}
			}
		}
		printf("Scenario %d:\n", i + 1);
		if (count1 == 0)
		{
			for (int j = 2; j <= 10000000; j++)
			{
				if (sum[j] == num2)
				{
					if (prime[j] == 0)
					{
						printf("%d\n", j);
						break;
					}
				}
			}
		}
		printf("\n");
		memset(sum, 0, sizeof(sum));
	}
}
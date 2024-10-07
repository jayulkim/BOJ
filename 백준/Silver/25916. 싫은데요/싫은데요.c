#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <memory.h>

long long int ary[500005] = { 0, };
long long int sum[500005] = { 0, };
int main(void)
{
	int num1 = 0;
	long long int num2 = 0;
	scanf("%d %lld", &num1, &num2);

	for (int i = 0; i < num1; i++)
	{
		scanf("%lld", &ary[i]);
	}
	sum[0] = ary[0];
	for (int i = 1; i < num1; i++)
	{
		sum[i] = sum[i - 1] + ary[i];
	}
	long long int max = 0;
	for (int i = 0; i < num1; i++)
	{
		//printf("%lld ", sum[i]);
		if (sum[i] <= num2)
		{
			max = sum[i];
		}
	}

	int start = 0;
	int end = 0;
	
	while (end < num1)
	{
		if (start == end)
		{
			end++;
		}
		if (sum[end] - sum[start] <= num2)
		{
			if (sum[end] - sum[start] > max)
			{
				max = sum[end] - sum[start];
				//printf("%lld %d %d\n", max, end, start);
			}
			end++;
		}
		else
		{
			start++;
		}
	}
	printf("%lld", max);


}
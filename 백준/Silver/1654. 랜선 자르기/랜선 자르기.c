#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long int ary[10005] = { 0, };

int main(void)
{
	int num1 = 0;
	long long int num2 = 0;
	scanf("%d %lld", &num1, &num2);
	long long int start = 1;
	long long int end = 0;
	for (int i = 0; i < num1; i++)
	{
		scanf("%lld", &ary[i]);
		if (ary[i] > end)
		{
			end = ary[i];
		}
	}
	long long int result = 0;
	while (start + 2 < end)
	{
		long long int sum = 0;
		long long int mid = (start + end) / 2;
		for (int i = 0; i < num1; i++)
		{
			sum += ary[i] / mid;
		}
		if (sum < num2)
		{
			end = mid;
		}
		else
		{
			if (result < mid)
			{
				result = mid;
			}
			start = mid;
		}	
	}
	for (long long int i = start; i <= end; i++)
	{
		long long int sum = 0;
		for (int j = 0; j < num1; j++)
		{
			sum += ary[j] / i;
		}
		if (sum >= num2)
		{
			if (result < i)
			{
				result = i;
			}
		}
	}
	printf("%lld", result);
}
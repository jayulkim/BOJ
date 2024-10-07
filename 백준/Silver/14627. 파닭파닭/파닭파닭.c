#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long int ary[1000005] = { 0, };
int compare(const void* num1, const void* num2)
{
	long long int a = *(long long int*)num1;
	long long int b = *(long long int*)num2;
	if (a > b)
	{
		return 1;
	}
	else if (a < b)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
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
	qsort(ary, num1, sizeof(long long int), compare);
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
	long long int result1 = 0;
	long long int result2 = 0;
	int index = 0;
	while (index < num1)
	{
		if (ary[index] / result > 0 && result1 < num2)
		{
			result1++;
			ary[index] -= result;
		}
		else if (ary[index] / result <= 0 && result1 < num2)
		{
			result2 += ary[index];
			index++;
		}
		else if (result1 == num2)
		{
			result2 += ary[index];
			index++;
		}
	}
	printf("%lld", result2);
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <math.h>

long long int ary[100005] = { 0, };

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
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%lld", &ary[i]);
	}
	qsort(ary, num1, sizeof(long long int), compare);

	long long int min = 3000000000;
	long long int result1 = 0;
	long long int result2 = 0;

	int start = 0;
	int end = num1 - 1;
	while (start < end)
	{
		long long int num2 = abs(ary[end] + ary[start]);
		if (ary[end] + ary[start] < 0)
		{
		
			if (num2 < min)
			{
				result1 = ary[start];
				result2 = ary[end];
				min = num2;
			}
			start++;
		}
		else if (ary[end] + ary[start] > 0)
		{
			
			if (num2 < min)
			{
				result1 = ary[start];
				result2 = ary[end];
				min = num2;
			}
			end--;
		}
		else
		{
			printf("%lld %lld", ary[start], ary[end]);
			return 0;
		}

	}
	printf("%lld %lld", result1, result2);
}
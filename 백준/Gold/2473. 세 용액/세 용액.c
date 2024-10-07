#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int ary[5005] = { 0, };

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
	
	long long int min = 50000000000;
	long long int result1 = 0;
	long long int result2 = 0;
	long long int result3 = 0;
	for (int i = 2; i < num1; i++)
	{
		int start = 0;
		int end = i - 1;
		while (start < end)
		{
			long long int temp = 0;
			if (ary[i] + ary[start] + ary[end] < 0)
			{
				temp = -(ary[i] + ary[start] + ary[end]);
			}
			else
			{
				temp = ary[i] + ary[start] + ary[end];
			}
			if (min > temp)
			{
				min = temp;
				result1 = ary[start];
				result2 = ary[end];
				result3 = ary[i];
			}
			if (ary[i] + ary[start] + ary[end] < 0)
			{
				start++;
			}
			else
			{
				end--;
			}
		}
	}
	printf("%lld %lld %lld", result1, result2, result3);
}
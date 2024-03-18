#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int ary[500005] = { 0, };
long long int sum[500005] = { 0, };
long long int ary1[500005] = { 0, };
long long int sum1[500005] = { 0, };

long long int result[500005] = { 0, };

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
	long long int num1 = 0;
	long long int num2 = 0;
	scanf("%lld %lld", &num1, &num2);
	for (int i = 0; i < num1; i++)
	{
		long long int num3 = 0;
		scanf("%lld", &num3);
		if (i % 2 == 1)
		{
			ary[num2 - num3+1]++;
		}
		else
		{
			ary1[num3]++;
		}
	}
	sum1[1] = ary1[num2];
	int index = 0;
	for (int i = num2 - 1; i >= 1; i--)
	{
		sum1[index + 1] = sum1[index] + ary1[i];
		index++;
	}
	int index1 = 0;
	sum[1] = ary[1];
	for (int i = 2; i <= num2; i++)
	{
		sum[i] = sum[i - 1] + ary[i];
	}
	int index2 = 0;
	for (int i = 1; i <= num2; i++)
	{
		result[index2] = sum[i] + sum1[index - i + 1];
		index2++;
	}
	qsort(result, index2, sizeof(long long int), compare);
	for (int i = 0; i < index2; i++)
	{
		if (result[i] != result[i + 1])
		{
			printf("%lld %d", result[i], i + 1);
			return 0;
		}
	}
}
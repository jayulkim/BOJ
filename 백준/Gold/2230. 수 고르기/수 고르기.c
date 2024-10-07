#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <memory.h>

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

	for (int i = 0; i < num1; i++)
	{
		scanf("%lld", &ary[i]);
	}
	qsort(ary, num1, sizeof(long long int), compare);

	int start = 0;
	int end = 1;

	long long int min = 2000000005;

	while (start < num1 - 1)
	{
		if (ary[end] - ary[start] >= num2)
		{
			if (ary[end] - ary[start] < min)
			{
				min = ary[end] - ary[start];

			}
			start++;
		}
		else
		{
			end++;
		}
		if (start == end)
		{
			end++;
		}

	}
	printf("%lld\n", min);

	

}
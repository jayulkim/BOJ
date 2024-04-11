#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int ary[605] = { 0, };

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
	for (int i = 0; i < num1 - 3; i++)
	{
		for (int j = i+3; j < num1; j++)
		{
			int start = i + 1;
			int end = j - 1;
			while (start < end)
			{	
				long long int temp = llabs(ary[i] + ary[j] - ary[end] - ary[start]);
				if (temp < min)
				{
					min = temp;
				}
				if (ary[i] + ary[j] - ary[end] - ary[start] <= 0)
				{
					end--;
				}
				else
				{
					start++;
				}
			}
		}
	}
	printf("%lld", min);
}
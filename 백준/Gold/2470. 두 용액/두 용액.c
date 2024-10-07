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
	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		scanf("%lld", &ary[i]);
	}
	
	qsort(ary, num1, sizeof(long long int), compare);
	
	long long int min = 3000000000;
	int start = 0;
	int end = num1 - 1;

	long long num2 = 0;
	long long num3 = 0;
	while (start < end)
	{

		if ((ary[start] + ary[end]) < 0)
		{
			if (llabs(ary[start] + ary[end]) < min)
			{
				min = llabs(ary[start] + ary[end]);
				num2 = ary[start];
				num3 = ary[end];
			}
			start++;
		}
		else if ((ary[start] + ary[end]) >= 0)
		{
			if (llabs(ary[start] + ary[end]) < min)
			{
				min = llabs(ary[start] + ary[end]);
				num2 = ary[start];
				num3 = ary[end];
			}
			end--;
		}

	}
	printf("%lld %lld\n", num2, num3);

	

}
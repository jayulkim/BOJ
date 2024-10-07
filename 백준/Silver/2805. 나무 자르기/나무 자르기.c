#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int ary[1000005] = { 0, };

long long int compare(const void* num1, const void* num2)
{
	return *(long long int*)num1 - *(long long int*)num2;
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
	long long int start = 0;
	long long int end = ary[num1 - 1];
	int count = 0;
	while (start < end -1)
	{
		long long int mid = (end + start) / 2;
		long long int sum = 0;
		for (int i = 0; i < num1; i++)
		{
			if (ary[i] > mid)
			{
				sum += (ary[i] - mid);
			}
		}
		if (sum < num2)
		{
			end = mid;
		}
		else if (sum == num2)
		{	
			break;
		}
		else
		{
			start = mid;
		}
	}
	printf("%lld\n", (end + start) / 2);

}
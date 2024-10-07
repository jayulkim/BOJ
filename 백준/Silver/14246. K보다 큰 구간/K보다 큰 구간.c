#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long int ary[100005] = { 0, };
long long int sum[100005] = { 0, };

int main(void)
{
	long long int num1 = 0;
	scanf("%lld", &num1);
	for (long long int i = 0; i < num1; i++)
	{
		scanf("%lld", &ary[i]);
	}
	long long int num2 = 0;
	scanf("%lld", &num2);

	sum[0] = ary[0];
	long long int count = 0;
	for (long long int i = 1; i < num1; i++)
	{
		sum[i] = sum[i - 1] + ary[i];
		if (sum[i] > num2)
		{
			count++;
		}
	}
	
	if (sum[0] > num2)
	{
		count++;
	}
	for (int i = 0; i < num1; i++)
	{
		//printf("%lld ", sum[i]);
	}
	long long int start = 0;
	long long int end = 1;
	while (end < num1)
	{
		if (sum[end] - sum[start] > num2)
		{
			count+= (num1 - end);
		//	printf("%d\n", num1 - end);
		//	printf("%d %d\n", start, end);
			start++;
			end = start + 1;
			//printf("%d %d\n", start, end);
		}
		else
		{
			end++;
		}
		
	}
	printf("%lld\n", count);
}
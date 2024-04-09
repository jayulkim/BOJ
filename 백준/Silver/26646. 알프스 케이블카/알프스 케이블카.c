#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long int ary[50005] = { 0, };

long long int Min(long long int num1, long long int num2)
{
	if (num1 > num2)
	{
		return num2;
	}
	else
	{
		return num1;
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
	long long int temp = (ary[0] - ary[1]) * (ary[0] - ary[1]) + (ary[0] + ary[1]) * (ary[0] + ary[1]);
	long long int sum = 2 * ary[1]; 
	if (num1 == 2)
	{
		printf("%d", temp);
		return 0;
	}
	for (int i = 1; i < num1 - 1; i++)
	{
		temp = Min(temp + (ary[i] - ary[i + 1]) * (ary[i] - ary[i + 1]) + (ary[i] + ary[i + 1]) * (ary[i] + ary[i + 1]), (ary[0] - ary[i + 1]) * (ary[0] - ary[i + 1]) + (ary[0] + ary[i + 1] + sum) * (ary[0] + ary[i + 1] + sum));
		sum += 2 * ary[i + 1];
	}
	printf("%lld", temp);
}


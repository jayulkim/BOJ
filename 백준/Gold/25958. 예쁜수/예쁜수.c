#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[5005] = { 0, };
long long int dp[5005] = { 0, };

int main(void)
{
	int index = 0;
	for (int i = 1; i <= 5000; i++)
	{
		int num1 = i;
		int sum = 0;
		while (num1 >= 1)
		{
			sum += (num1 % 10);
			num1 /= 10;
		}
		if (i % sum == 0)
		{
			ary[index] = i;
			index++;
		}
	}
	long long int num1 = 0;
	long long int num2 = 0;
	scanf("%lld %lld", &num1, &num2);
	dp[0] = 1;
	for (int i = 0; i < index; i++)
	{
		for (long long int j = ary[i]; j <= num1; j++)
		{
			dp[j] += (dp[j - ary[i]] %= num2);
			dp[j] %= num2;
		}
	}
	printf("%lld", dp[num1] % num2);
}

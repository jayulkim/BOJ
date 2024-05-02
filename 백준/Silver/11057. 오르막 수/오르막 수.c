#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <memory.h>

unsigned long long int dp[1001][11] = { 0, };

int main(void)
{
	for (unsigned long long int  i = 0; i <= 9; i++)
	{
		dp[1][i] = 1LL;
	}
	for (int i = 2; i <= 1000; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[i][j] += (dp[i - 1][k] % 10007);
			}
		}
	}
	int num1 = 0;
	scanf("%d", &num1);
	unsigned long long int result = 0;
	for (int i = 0; i < 10; i++)
	{
		result += (dp[num1][i] % 10007);
		result %= 10007;
	}
	printf("%llu", result % 10007);
}
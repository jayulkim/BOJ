#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <memory.h>

unsigned long long int dp[65][11] = { 0, };

int main(void)
{
	for (unsigned long long int  i = 0; i <= 9; i++)
	{
		dp[1][i] = 1LL;
	}
	for (int i = 2; i <= 64; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[i][j] += dp[i - 1][k];
			}
		}
	}
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		scanf("%d", &num2);
		unsigned long long int result = 0;
		for (int j = 0; j < 10; j++)
		{
			result += dp[num2][j];
		}
		printf("%llu\n", result);
	}
}
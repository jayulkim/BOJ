#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int dp[101][11] = { 0, };

int main(void)
{
	for (int i = 0; i <= 9; i++)
	{
		dp[1][i] = 1;
	}
	for (int i = 2; i <= 100; i++)
	{
		dp[i][0] = dp[i - 1][1];
		dp[i][9] = dp[i - 1][8];
		for (int j = 1; j <= 8; j++)
		{
			dp[i][j] += dp[i - 1][j - 1] % 1000000000;
			dp[i][j] += dp[i - 1][j + 1] % 1000000000;
			dp[i][j] %= 1000000000;
		}
	}
	int num1 = 0;
	scanf("%d", &num1);
	long long int sum = 0;
	for (int i = 1; i <= 9; i++)
	{
		sum += (dp[num1][i] % 1000000000);
		sum %= 1000000000;
	}
	printf("%lld", sum % 1000000000);
}
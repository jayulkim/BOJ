#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <memory.h>

int ary[3][100001] = { 0, };
int dp[3][100001] = { 0, };

int Max(int num1, int num2)
{
	if (num1 > num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		scanf("%d", &num2);
		for (int j = 0; j < num2; j++)
		{
			scanf("%d", &ary[0][j]);
		}
		for (int j = 0; j < num2; j++)
		{
			scanf("%d", &ary[1][j]);
		}
		dp[0][0] = ary[0][0];
		dp[1][0] = ary[1][0];
		dp[0][1] = Max(ary[1][0] + ary[0][1], dp[0][0]);
		dp[1][1] = Max(ary[1][1] + ary[0][0], dp[1][0]);
		for (int j = 2; j < num2; j++)
		{
			dp[0][j] = Max(Max(dp[1][j - 1], dp[0][j - 2] + ary[1][j - 1]) + ary[0][j], dp[0][j - 1]);
			dp[1][j] = Max(Max(dp[0][j - 1], dp[1][j - 2] + ary[0][j - 1]) + ary[1][j], dp[1][j - 1]);
		}
		int result = 0;
		for (int j = 0; j < num2; j++)
		{
			if (result < dp[0][j])
			{
				result = dp[0][j];
			}
		}
		for (int j = 0; j < num2; j++)
		{
			if (result < dp[1][j])
			{
				result = dp[1][j];
			}
		}
		printf("%d\n", result);
		memset(dp, 0, sizeof(dp));
	}
}
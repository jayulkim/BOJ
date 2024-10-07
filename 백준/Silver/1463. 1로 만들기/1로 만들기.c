#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int dp[1000001] = { 0, };

int Min(int num1, int num2)
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
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 4; i <= num1; i++)
	{
		if (i % 6 == 0)
		{
			dp[i] = Min(dp[i / 3] + 1, dp[i / 2] + 1);
		}
		else if (i % 2 == 0)
		{
			dp[i] = Min(dp[i - 1] + 1, dp[i / 2] + 1);
		}
		else if (i % 3 == 0)
		{
			dp[i] = Min(dp[i - 1] + 1, dp[i / 3] + 1);
		}
		else
		{
			dp[i] = dp[i - 1] + 1;
		}
	}
	printf("%d", dp[num1]);
}
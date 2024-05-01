#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int dp[10001] = { 0, };
int ary[10001] = { 0, };

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
	for (int i = 1; i <= num1; i++)
	{
		scanf("%d", &ary[i]);
	}
	if (num1 == 1)
	{
		printf("%d", ary[1]);
		return 0;
	}
	else if (num1 == 2)
	{
		printf("%d", ary[2] + ary[1]);
		return 0;
	}
	dp[1] = ary[1];
	dp[2] = ary[1] + ary[2];
	int max = dp[2];
	for (int i = 3; i <= num1; i++)
	{
		dp[i] = Max(Max(dp[i - 3] + ary[i - 1], dp[i - 2]) + ary[i], dp[i - 1]);
		if (max < dp[i])
		{
			max = dp[i];
		}
	}
	printf("%d", max);
}
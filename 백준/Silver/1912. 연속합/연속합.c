#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int dp[100001] = { 0, };
int ary[100001] = { 0, };

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
		scanf("%d", &ary[i]);
	}
	int max = -1001;
	dp[0] = ary[0];
	if (max < dp[0])
	{
		max = dp[0];
	}
	for (int i = 1; i < num1; i++)
	{
		dp[i] = Max(dp[i - 1] + ary[i], ary[i]);
		if (max < dp[i])
		{
			max = dp[i];
		}
	}
	printf("%d", max);
}
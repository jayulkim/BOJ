#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int dp[301] = { 0, };
int ary[301] = { 0, };

int Max(int num1, int num2)
{
	if (num1 < num2)
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
	for (int i = 1; i <= num1; i++)
	{
		scanf("%d", &ary[i]);
	}
	dp[1] = ary[1];
	dp[2] = ary[1] + ary[2];
	for (int i = 3; i <= num1; i++)
	{
		dp[i] = Max(dp[i - 2], dp[i - 3] + ary[i - 1]) + ary[i];
	}
	printf("%d", dp[num1]);
}
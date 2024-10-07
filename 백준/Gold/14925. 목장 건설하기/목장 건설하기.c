#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

int pew[1000001] = { 0, };
int ary[1001][1001] = { 0, };
int dp[1001][1001] = { 0, };
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
	for (int i = 1; i <= 1000; i++)
	{
		pew[i * i] = 1;
	}
	
	int max = 0;
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	for (int i = 1; i <= num1; i++)
	{
		for (int j = 1; j <= num2; j++)
		{
			scanf(" %d", &ary[i][j]);
		}
	}
	for (int i = 1; i <= num1; i++)
	{
		for (int j = 1; j <= num2; j++)
		{
			if (pew[ary[i][j]] == 0 && ary[i][j] == 0)
			{
				if (pew[dp[i - 1][j]] == 1 && pew[dp[i][j - 1]] == 1 && pew[dp[i - 1][j - 1]] == 1)
				{
					dp[i][j] = (sqrt(Min(Min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1])) + 1) * (sqrt(Min(Min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1])) + 1);
				}
				else
				{
					dp[i][j] = 1;
				}
			}
			else
			{
				dp[i][j] = 0;
			}
			if (max < sqrt(dp[i][j]))
			{
				max = sqrt(dp[i][j]);
			}
		}
	}
	printf("%d", max);
}

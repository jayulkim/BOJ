#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int dp[40001] = { 0, };
int mg[31] = { 0, };
int ary[8] = { 0, };

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	int sum = 0;
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &mg[i]);
		sum += mg[i];
	}
	dp[0] = 1;
	int num2 = 0;
	scanf("%d", &num2);
	for (int i = 0; i < num2; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (int i = 0; i < num1; i++)
	{
		for (int j = sum; j >= 0; j--)
		{
			if (dp[j] == 1)
			{
				if (j + mg[i] <= sum && dp[j + mg[i]] == 0)
				{
					dp[j + mg[i]] = 1;
				}
			}
		}
		for (int j = 0; j <= sum; j++)
		{
			if (dp[j] == 1)
			{
				if (j > mg[i])
				{
					if (j - mg[i] >= 1 && dp[j - mg[i]] == 0)
					{
						dp[j - mg[i]] = 1;
					}
				}
				else
				{
					if (mg[i] - j >= 1 && dp[mg[i] - j] == 0)
					{
						dp[mg[i] - j] = 1;
					}
				}
			}
		}
	}
	
	for (int i = 0; i < num2; i++)
	{
		if (dp[ary[i]] == 1)
		{
			printf("Y ");
		}
		else
		{
			printf("N ");
		}
	}
}

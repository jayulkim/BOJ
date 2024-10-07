#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

char ary[3001][3001] = { 0, };
long long int dp[3001][3001] = { 0, };
long long int Min(long long int num1, long long int num2)
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
	int max = 0;
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	for (int i = 1; i <= num1; i++)
	{
		for (int j = 1; j <= num2; j++)
		{
			scanf(" %c", &ary[i][j]);
		}
	}
	long long int result = num1 * num2;
	for (int i = 1; i <= num1; i++)
	{
		for (int j = 1; j <= num2; j++)
		{
			if (ary[i][j] == 'W')
			{
				if (ary[i - 1][j] == 'B' && ary[i][j - 1] == 'B' && ary[i - 1][j - 1] == 'W')
				{
					if (dp[i - 1][j] != 0 && dp[i][j - 1] != 0 && dp[i - 1][j - 1] != 0)
					{
						dp[i][j] = Min(Min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
					}
					else
					{
						dp[i][j] = 1;
					}
				}
			}
			else if (ary[i][j] == 'B')
			{
				if (ary[i - 1][j] == 'W' && ary[i][j - 1] == 'W' && ary[i - 1][j - 1] == 'B')
				{
					if (dp[i - 1][j] != 0 && dp[i][j - 1] != 0 && dp[i - 1][j - 1] != 0)
					{
						dp[i][j] = Min(Min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
					}
					else
					{
						dp[i][j] = 1;
					}
				}
			}
			result += dp[i][j];
		}
	}
	printf("%lld", result);
}

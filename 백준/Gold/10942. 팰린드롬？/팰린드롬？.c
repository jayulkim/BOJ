#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[2005] = { 0, };
int dp[2005][2005] = { 0, };

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
		dp[i][i] = 1;
		if (i != 0)
		{
			if (ary[i] == ary[i - 1])
			{
				dp[i - 1][i] = 1;
			}
		}
	}
	for (int i = num1 / 2; i >= 0; i--)
	{
		for (int j = i + 2; j < num1; j++)
		{
			if (j == i + 2)
			{
				if (ary[j] == ary[i])
				{
					dp[i][j] = 1;
				}
			}
			else
			{
				if (ary[i] == ary[j] && dp[i + 1][j - 1] == 1)
				{
					dp[i][j] = 1;
				}
			}
		}
	}
	for (int i = num1 / 2; i < num1; i++)
	{
		for (int j = i - 2; j >= 0; j--)
		{
			if (j == i - 2)
			{
				if (ary[j] == ary[i])
				{
				//	printf("%d %d\n", i, j);
					dp[j][i] = 1;
				}
			}
			else
			{
				if (ary[i] == ary[j] && dp[j + 1][i - 1] == 1)
				{
					dp[j][i] = 1;
				}
			}
		}
	}
	int num2 = 0;
	scanf("%d", &num2);
	for (int i = 0; i < num2; i++)
	{
		int num3 = 0;
		int num4 = 0;
		scanf("%d %d", &num3, &num4);
		printf("%d\n", dp[num3-1][num4-1]);
	}
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int dp[1000001] = { 0, };
int ary[1000001] = { 0, };
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
	ary[1] = 1;
	ary[2] = 1;
	ary[3] = 2;
	int num1 = 0;
	scanf("%d", &num1);
	int num2 = num1;
	for (int i = 4; i <= num1; i++)
	{
		if (i % 6 == 0)
		{
			dp[i] = Min(dp[i / 3] + 1, dp[i / 2] + 1);
			if (dp[i / 3] > dp[i / 2])
			{
				ary[i] = 1;
			}
			else
			{
				ary[i] = 2;
			}
		}
		else if (i % 2 == 0)
		{
			dp[i] = Min(dp[i - 1] + 1, dp[i / 2] + 1);
			if (dp[i - 1] > dp[i / 2])
			{
				ary[i] = 3;
			}
			else
			{
				ary[i] = 4;
			}
		}
		else if (i % 3 == 0)
		{
			dp[i] = Min(dp[i - 1] + 1, dp[i / 3] + 1);
			if (dp[i - 1] > dp[i / 3])
			{
				ary[i] = 5;
			}
			else
			{
				ary[i] = 6;
			}
		}
		else
		{
			dp[i] = dp[i - 1] + 1;
			ary[i] = 7;
		}
	}
	printf("%d\n", dp[num1]);
	printf("%d ", num2);
	while (num2 > 1)
	{
		if (ary[num2] == 1)
		{
			printf("%d ", num2 /= 2);
		}
		else if (ary[num2] == 2)
		{
			printf("%d ", num2 /= 3);
		}
		else if (ary[num2] == 3)
		{
			printf("%d ", num2 /= 2);
		}
		else if (ary[num2] == 4)
		{
			printf("%d ", num2 -= 1);
		}
		else if (ary[num2] == 5)
		{
			printf("%d ", num2 /= 3);
		}
		else if (ary[num2] == 6)
		{
			printf("%d ", num2 -= 1);
		}
		else if (ary[num2] == 7)
		{
			printf("%d ", num2 -= 1);
		}
	}
}
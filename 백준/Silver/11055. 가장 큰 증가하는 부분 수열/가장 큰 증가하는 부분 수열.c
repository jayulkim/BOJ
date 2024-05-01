#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int dp[1001] = { 0, };
int ary[1001] = { 0, };

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
	}
	dp[0] = ary[0];
	int result = dp[0];
	for (int i = 1; i < num1; i++)
	{
		int max = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (ary[i] > ary[j])
			{
				if (max < dp[j])
				{
					max = dp[j];
				}
			}
		}
		dp[i] = max + ary[i];
		if (result < dp[i])
		{
			result = dp[i];
		}
	}
	printf("%d", result);
}
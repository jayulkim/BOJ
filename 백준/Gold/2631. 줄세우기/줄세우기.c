#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int dp[201] = { 0, };
int ary[201] = { 0, };
int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	dp[0] = 1;
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
	}
	int result = 0;
	for (int i = 1; i < num1; i++)
	{
		int max = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (ary[i] > ary[j])
			{
				if (dp[j] > max)
				{
					max = dp[j];
				}
			}
		}
		dp[i] = max + 1;
		if (dp[i] > result)
		{
			result = dp[i];
		}
	}
	printf("%d", num1 - result);
}

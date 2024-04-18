#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[105] = { 0, };
int dp[100005] = { 0, };

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
	}
	dp[0] = 1;
	for (int i = 0; i < num1; i++)
	{
		for (int j = ary[i]; j <= num2; j++)
		{
			dp[j] += dp[j - ary[i]];
		}
	}
	printf("%d", dp[num2]);
}

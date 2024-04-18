#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int ary[25] = { 0, };
int dp[10005] = {0,};

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	for (int k = 0; k < num; k++)
	{
		int num1 = 0;
		scanf("%d", &num1);
		int num2 = 0;
		
		for (int i = 0; i < num1; i++)
		{
			scanf("%d", &ary[i]);
		}
		scanf("%d", &num2);
		dp[0] = 1;

		for (int i = 0; i < num1; i++)
		{
			for (int j = ary[i]; j <= num2; j++)
			{
				dp[j] += dp[j - ary[i]];
			}
		}
		printf("%d\n", dp[num2]);
		memset(dp, 0, sizeof(dp));
	}
}

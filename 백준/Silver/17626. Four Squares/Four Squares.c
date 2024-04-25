#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int dp[50001] = { 0, };

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 1; i <= num1; i++)
	{
		int minus = 1;
		int num2 = i;
		int min = 50001;
		while (num2 - minus * minus >= 0)
		{
			if (min > dp[num2 - minus * minus])
			{
				min = dp[num2 - minus * minus];
			}
			minus++;
		}
		dp[i] = min + 1;
	}
	printf("%d", dp[num1]);
}
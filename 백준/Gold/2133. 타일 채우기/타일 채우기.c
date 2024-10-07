#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long int dp[31] = { 0, };

int main(void)
{
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	dp[3] = 0;
	dp[4] = 11;
	for (int i = 6; i <= 30; i += 2)
	{
		dp[i] = dp[i - 2] * 3LL;
		for (int j = i - 4; j >= 2; j -= 2)
		{
			dp[i] += 2LL * dp[j];
		}
		dp[i] += 2;
	}
	int num1 = 0;
	scanf("%d", &num1);
	printf("%lld", dp[num1]);
}

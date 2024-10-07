#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[100005] = { 0, };
long long int dp[100005] = { 0, };

int main(void)
{
	dp[0] = 1;
	dp[1] = 0;
	for (int i = 2; i <= 100000; i++)
	{
		if (ary[i] == 0)
		{
			//dp[i]++;
			for (int j = 2 * i; j <= 100000; j += i)
			{
				ary[j] = 1;
			}
			for (int j = i; j <= 100000; j++)
			{
				dp[j] += (dp[j - i] %= 1000000007);
				dp[j] %= 1000000007;
			}
		}
	}
	//printf("%lld", dp[20000] % 1000000007);
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		scanf("%d", &num2);
		printf("%lld\n", dp[num2] % 1000000007);
	}
}

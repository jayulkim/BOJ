#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[40005] = { 0, };
long long int dp[40005] = { 0, };

int main(void)
{
	dp[0] = 1;
	dp[1] = 0;
	for (int i = 2; i <= 40000; i++)
	{
		if (ary[i] == 0)
		{
			//dp[i]++;
			for (int j = 2 * i; j <= 40000; j += i)
			{
				ary[j] = 1;
			}
			for (int j = i; j <= 40000; j++)
			{
				dp[j] += (dp[j - i] %= 123456789);
				dp[j] %= 123456789;
			}
		}
	}
	//printf("%lld", dp[20000] % 1000000007);
	int num1 = 0;
	scanf("%d", &num1);
	printf("%lld\n", dp[num1] % 123456789);
}

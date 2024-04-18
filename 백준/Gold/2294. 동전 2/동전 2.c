#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[105] = { 0, };
int dp[10005] = { 0, };
int compare(const void* num1, const void* num2)
{
	return *(int*)num1 - *(int*)num2;
}
int main(void)
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (int i = 1; i <= 10000; i++)
	{
		dp[i] = 10005;
	}
	qsort(ary, num1, sizeof(int), compare);
	dp[0] = 1;

	for (int i = 0; i < num1; i++)
	{
	//	dp[ary[i]]++;
		for (int j = ary[i]; j <= num2; j++)
		{
			if (dp[j] > dp[j - ary[i]] + 1)
			{
				dp[j] = dp[j - ary[i]] + 1;
			}
			else
			{
			//	dp[j] = dp[ary[i]];
			}
		}
	}
	if (dp[num2] == 10005)
	{
		printf("-1");
		return 0;
	}
	printf("%d", dp[num2] - 1);
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[1005] = { 0, };
int dp[1005] = { 0, };

int compare(const void* num1, const void* num2)
{
	return *(int*)num1 - *(int*)num2;
}

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 1; i <= num1; i++)
	{
		scanf("%d", &ary[i]);
	}
	
	for (int i = 1; i <= num1; i++)
	{
		int max = 0;
		int index = 0;
		for (int j = i - 1; j >= 1; j--)
		{
			if (ary[i] < ary[j])
			{
				if (max < dp[j])
				{
					max = dp[j];
					index = j;
				}
			}
		}
		dp[i] = dp[index] + 1;
	}
	qsort(dp, num1 + 1, sizeof(int), compare);
	printf("%d", dp[num1]);
}
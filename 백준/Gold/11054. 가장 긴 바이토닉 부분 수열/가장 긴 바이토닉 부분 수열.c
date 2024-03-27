#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[1005] = { 0, };
int ary1[1005] = { 0, };
int dp[1005] = { 0, };
int dp1[1005] = { 0, };
int result[1005] = { 0, };

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
			if (ary[i] > ary[j])
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
	for (int i = 1; i <= num1; i++)
	{
		ary1[i] = ary[num1 + 1 - i];
	}
	for (int i = 1; i <= num1; i++)
	{
		int max1 = 0;
		int index1 = 0;
		for (int j = i - 1; j >= 1; j--)
		{
			if (ary1[i] > ary1[j])
			{
				if (max1 < dp1[j])
				{
					max1 = dp1[j];
					index1 = j;
				}
			}
		}
		dp1[i] = dp1[index1] + 1;
	}

	for (int i = 1; i <= num1; i++)
	{
		if (i == 1)
		{
			result[i] = dp1[num1 - i + 1];
		}
		else if (i == num1)
		{
			result[i] = dp[i];
		}
		else
		{
			result[i] = dp[i] + dp1[num1 - i + 1] -1;
		}
		//printf("%d ", dp1[num1 - i + 1]);
	}
	qsort(result, num1 + 1, sizeof(int), compare);
	printf("%d",result[num1]);
}
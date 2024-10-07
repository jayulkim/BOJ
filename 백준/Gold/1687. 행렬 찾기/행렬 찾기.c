#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char map[334][334];
int dp[334][334] = { 0, };

int Min(int num1, int num2)
{
	if (num1 < num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}
void solve()
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	int max = 0;
	for (int i = 1; i <= num1; i++)
	{
		for (int j = 1; j <= num2; j++)
		{
			scanf(" %c", &map[i][j]);
		}
	}
	for (int i = 1; i <= num1; i++)
	{
		for (int j = 1; j <= num2; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + map[i][j] - 48;
		}
	}
	for (int i = 1; i <= num2; i++)
	{
		dp[num1 + 1][i] = 1;
	}
	for (int k = 1; k <= num2; k++)
	{
		for (int i = 1; i <= k; i++)
		{
			int pre = 0;
			int size = 0;
			for (int j = 1; j <= num1 + 1; j++)
			{
				int startx = i; 
				int starty = j;
				int endx = k; 
				int endy = j; 
				int sum = dp[endy][endx] - dp[starty - 1][endx] - dp[endy][startx - 1] + dp[starty - 1][startx - 1];
				if (sum == 0)
				{
					size += (k - i + 1);
				}
				else
				{
					if (size > max)
					{
						max = size;
					}
					size = 0;
				}
				pre = sum;
			}
		}
	}
	printf("%d", max);
}
int main(void)
{
	solve();
}
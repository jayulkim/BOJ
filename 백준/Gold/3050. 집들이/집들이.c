#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char map[401][401];
int dp[401][401] = { 0, };

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
			if (map[i][j] == 'X')
			{
				map[i][j] = '.' + 1;
			}
		}
	}
	for (int i = 1; i <= num1; i++)
	{
		for (int j = 1; j <= num2; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + map[i][j] - '.';
		}		
	}

	for (int k = 1; k <= num2; k++)
	{
		for (int i = 1; i <= k; i++)
		{
			int size = 0;
			for (int j = 1; j <= num1 ; j++)
			{
				int startx = i;
				int starty = j;
				int endx = k;
				int endy = j; 
				int sum = dp[endy][endx] - dp[starty - 1][endx] - dp[endy][startx - 1] + dp[starty - 1][startx - 1];
				if (sum == 0)
				{
					size += (k - i + 1);
					if (2 * (k - i + 1) + (2 * size) / (k - i + 1) > max)
					{
						max = 2 * (k - i + 1) + (2 * size) / (k - i + 1);
					}
				}
				else
				{
					size = 0;
				}
			}
		}
	}
	printf("%d", max - 1);
}
int main(void)
{
	solve();
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long int ary[2005][2005] = { 0, };
long long int sum[2005][2005] = { 0, };

long long int ary1[2005][2005] = { 0, };
long long int sum1[2005][2005] = { 0, };
char map[2005][2005] = { 0, };

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	scanf("%d %d %d", &num1, &num2, &num3);
	for (int i = 1; i <= num1; i++)
	{
		for (int j = 1; j <= num2; j++)
		{
			scanf(" %c", &map[i][j]);
		}
	}
	for (int i = 1; i <= num1; i+=2)
	{
		for (int j = 1; j <= num2; j+=2)
		{
			if (map[i][j] != 'W')
			{
				ary[i][j] = 1;
			}
			if (map[i][j + 1] != 'B')
			{
				ary[i][j + 1] = 1;
			}
		}
	}
	for (int i = 2; i <= num1; i += 2)
	{
		for (int j = 2; j <= num2+1; j += 2)
		{
			if (map[i][j] != 'W')
			{
				ary[i][j] = 1;
			}
			if (map[i][j - 1] != 'B')
			{
				ary[i][j - 1] = 1;
			}
		}
	}
	for (int i = 1; i <= num1; i++)
	{
		for (int j = 1; j <= num2; j++)
		{
	//		printf("%d ", ary[i][j]);
			sum[i][j] = ary[i][j] + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
		}
	//	printf("\n");
	}
	for (int i = 1; i <= num1; i++)
	{
		for (int j = 1; j <= num2; j++)
		{
			//printf("%d ", sum[i][j]);
		}
		//printf("\n");
	}

	long long int min = 4000000005;
	for (int i = 1; i + num3 <= num1+1; i++)
	{
		for (int j = 1; j + num3 <= num2+1; j++)
		{
			int x1 = i;
			int y1 = j;
			int x2 = x1 + num3-1;
			int y2 = y1 + num3-1;
			if (min > sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1])
			{
				min = sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1];
			}
		}
	}
	for (int i = 1; i <= num1; i += 2)
	{
		for (int j = 1; j <= num2; j += 2)
		{
			if (map[i][j] != 'B')
			{ 
				ary1[i][j] = 1;
			}
			if (map[i][j + 1] != 'W')
			{
				ary1[i][j + 1] = 1;
			}
		}
	}
	for (int i = 2; i <= num1; i += 2)
	{
		for (int j = 2; j <= num2+1; j += 2)
		{
			if (map[i][j] != 'B')
			{
				ary1[i][j] = 1;
			}
			if (map[i][j - 1] != 'W')
			{
				ary1[i][j - 1] = 1;
			}
		}
	}
	for (int i = 1; i <= num1; i++)
	{
		for (int j = 1; j <= num2; j++)
		{
		//	printf("%d ", ary1[i][j]);
			sum1[i][j] = ary1[i][j] + sum1[i][j - 1] + sum1[i - 1][j] - sum1[i - 1][j - 1];
		}
	//	printf("\n");
	}
	for (int i = 1; i + num3 <= num1+1; i++)
	{
		for (int j = 1; j + num3 <= num2+1; j++)
		{
			int x1 = i;
			int y1 = j;
			int x2 = x1 + num3-1;
			int y2 = y1 + num3-1;
		//	printf("%d %d\n", i, j);
			if (min > sum1[x2][y2] - sum1[x2][y1-1] - sum1[x1-1][y2] + sum1[x1-1][y1-1])
			{
				min = sum1[x2][y2] - sum1[x2][y1-1] - sum1[x1-1][y2] + sum1[x1-1][y1-1];
			}
			//printf("%d ", sum1[x2][y2] - sum1[x2][y1 - 1] - sum1[x1 - 1][y2] + sum1[x1 - 1][y1 - 1]);
		}
	}
	for (int i = 1; i <= num1; i++)
	{
		for (int j = 1; j <= num2; j++)
		{
	//		printf("%d ", sum1[i][j]);
		}
	//	printf("\n");
	}
	printf("%lld\n", min);
}
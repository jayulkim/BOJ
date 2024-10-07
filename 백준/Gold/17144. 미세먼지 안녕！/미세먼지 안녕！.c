#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int map[55][55] = { 0, };
int map1[55][55] = { 0, };

int main(void)
{
	int R = 0;
	int C = 0;
	int sec = 0;
	scanf("%d %d %d", &R, &C, &sec);
	int airup = 0;
	int airdown = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == -1)
			{
				airup = i - 1;
				airdown = i;
			}
		}
	}
	while (sec--)
	{
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (map[i][j] != -1)
				{
					int up = 0;
					int down = 0;
					int left = 0;
					int right = 0;
					int num1 = map[i + 1][j] / 5;
					int num2 = map[i - 1][j] / 5;
					int num3 = map[i][j + 1] / 5;
					int num4 = map[i][j - 1] / 5;
					if (i + 1 < R && map[i + 1][j] != -1 && map[i + 1][j] != 0)
					{
						down = 1;
					}
					if (i - 1 >= 0 && map[i - 1][j] != -1 && map[i - 1][j] != 0)
					{
						up = 1;
					}
					if (j + 1 < C && map[i][j + 1] != -1 && map[i][j + 1] != 0)
					{
						right = 1;
					}
					if (j - 1 >= 0 && map[i][j - 1] != -1 && map[i][j - 1] != 0)
					{
						left = 1;
					}

					if (down == 1)
					{
						map1[i][j] += map[i + 1][j] / 5;
						map1[i + 1][j] -= map[i + 1][j] / 5;
					}
					if (up == 1)
					{
						map1[i][j] += map[i - 1][j] / 5;
						map1[i - 1][j] -= map[i - 1][j] / 5;
					}
					if (right == 1)
					{
						map1[i][j] += map[i][j + 1] / 5;
						map1[i][j + 1] -= map[i][j + 1] / 5;
					}
					if (left == 1)
					{
						map1[i][j] += map[i][j - 1] / 5;
						map1[i][j - 1] -= map[i][j - 1] / 5;
					}
				}
				}
				
		}
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (map[i][j] != -1)
				{
					map[i][j] += map1[i][j];
				}
			}
		}
		if (map[airup - 1][0] != 0)
		{
			map[airup - 1][0] = 0;
		}
		for (int i = airup - 2; i >= 0; i--)
		{
			if (map[i][0] != 0)
			{
				map[i + 1][0] = map[i][0];
				map[i][0] = 0;
			}
		}
		for (int i = 1; i < C; i++)
		{
			if (map[0][i] != 0)
			{
				map[0][i - 1] = map[0][i];
				map[0][i] = 0;
			}
		}
		for (int i = 1; i <= airup; i++)
		{
			if (map[i][C - 1] != 0)
			{
				map[i - 1][C - 1] = map[i][C - 1];
				map[i][C - 1] = 0;
			}
		}
		for (int i = C-1; i >= 1; i--)
		{
			if (map[airup][i] != 0)
			{
				map[airup][i + 1] = map[airup][i];
				map[airup][i] = 0;
			}
		}
		if (map[airdown + 1][0] != 0)
		{
			map[airdown + 1][0] = 0;
		}
		for (int i = airdown + 2; i < R; i++)
		{
			if (map[i][0] != 0)
			{
				map[i - 1][0] = map[i][0];
				map[i][0] = 0;
			}
		}
		for (int i = 1; i < C; i++)
		{
			if (map[R - 1][i] != 0)
			{
				map[R - 1][i - 1] = map[R - 1][i];
				map[R - 1][i] = 0;
			}
		}
		for (int i = R - 1; i >= airdown; i--)
		{
			if (map[i][C - 1] != 0)
			{
				map[i + 1][C - 1] = map[i][C - 1];
				map[i][C - 1] = 0;
			}
		}
		for (int i = C-1; i >= 1; i--)
		{
			if (map[airdown][i] != 0)
			{
				map[airdown][i + 1] = map[airdown][i];
				map[airdown][i] = 0;
			}
		}
		memset(map1, 0, sizeof(map1));
	}
	int sum = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] != -1)
			{
				sum += map[i][j];
			}
		}
	}
	printf("%d\n", sum);
}
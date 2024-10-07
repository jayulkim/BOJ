#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char map[105][105];
int visit1[105][105];
int visit2[105][105];
long long int sum1[100005];
int index1 = 0;
long long int sum2[100005];
int index2 = 0;
void dfs1(int y, int x, int m, int n)
{
	visit1[y][x] = 1;
	sum1[index1]++;
	if (x + 1 < n && visit1[y][x + 1] == 0 && map[y][x + 1] == '0')
	{
		dfs1(y, x + 1, m, n);
	}
	if (x - 1 >= 0 && visit1[y][x - 1] == 0 && map[y][x - 1] == '0')
	{
		dfs1(y, x - 1, m, n);
	}
	if (y + 1 < m && visit1[y + 1][x] == 0 && map[y + 1][x] == '0')
	{
		dfs1(y + 1, x, m, n);
	}
	if (y - 1 >= 0 && visit1[y - 1][x] == 0 && map[y - 1][x] == '0')
	{
		dfs1(y - 1, x, m, n);
	}
}
void dfs2(int y, int x, int m, int n)
{
	visit2[y][x] = 1;
	sum2[index2]++;
	if (x + 1 < n && visit2[y][x + 1] == 0 && map[y][x + 1] == '1')
	{
		dfs2(y, x + 1, m, n);
	}
	if (x - 1 >= 0 && visit2[y][x - 1] == 0 && map[y][x - 1] == '1')
	{
		dfs2(y, x - 1, m, n);
	}
	if (y + 1 < m && visit2[y + 1][x] == 0 && map[y + 1][x] == '1')
	{
		dfs2(y + 1, x, m, n);
	}
	if (y - 1 >= 0 && visit2[y - 1][x] == 0 && map[y - 1][x] == '1')
	{
		dfs2(y - 1, x, m, n);
	}
}

int main(void)
{
	int n = 0, m = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char str;
			scanf(" %c", &str);
			if (str == 'W')
			{
				map[i][j] = '0';
			}
			else
			{
				map[i][j] = '1';
			}
		}
	}
	while (1)
	{
		int count = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (map[i][j] == '0' && visit1[i][j] == 0)
				{
					dfs1(i, j, m, n);
					count++;
					index1++;
					break;
				}
			}
			if (count != 0)
			{
				break;
			}
		}
		if (count == 0)
		{
			break;
		}	
	}
	while (1)
	{
		int count = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (map[i][j] == '1' && visit2[i][j] == 0)
				{
					dfs2(i, j, m, n);
					count++;
					index2++;
					break;
				}
			}
			if (count != 0)
			{
				break;
			}
		}
		if (count == 0)
		{
			break;
		}
	}
	long long int result1 = 0;
	long long int result2 = 0;
	for (int i = 0; i < index1; i++)
	{
		result1 += (sum1[i] * sum1[i]);
	}
	for (int i = 0; i < index2; i++)
	{
		result2 += (sum2[i] * sum2[i]);
	}
	printf("%lld %lld", result1, result2);
}
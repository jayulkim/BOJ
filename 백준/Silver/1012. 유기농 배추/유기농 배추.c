#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
int visit[51][51] = { 0, };
int map[51][51] = { 0, };
void dfs(int x, int y, int m, int n)
{
	visit[x][y] = 1;
	if (map[x + 1][y] == 1 && x + 1 < m && visit[x + 1][y] == 0)
	{
		dfs(x + 1, y, m, n);
	}
	if (map[x - 1][y] == 1 && x - 1 >= 0 && visit[x - 1][y] == 0)
	{
		dfs(x - 1, y, m, n);
	}
	if (map[x][y + 1] == 1 && y + 1 < n && visit[x][y + 1] == 0)
	{
		dfs(x, y + 1, m, n);
	}
	if (map[x][y - 1] == 1 && y - 1 >= 0 && visit[x][y - 1] == 0)
	{
		dfs(x, y - 1, m, n);
	}
}

int main(void)
{
	int test = 0;
	scanf("%d", &test);
	for (int i = 0; i < test; i++)
	{
		int n = 0, m = 0, k = 0, result = 0;
		scanf("%d %d %d", &m, &n, &k);
		for (int j = 0; j < k; j++)
		{
			int x = 0, y = 0;
			scanf("%d %d", &x, &y);
			map[x][y] = 1;
		}
		while (1)
		{
			int count = 0;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (visit[i][j] == 0 && map[i][j] == 1)
					{
						dfs(i, j, m, n);
						count++;
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
			result++;
		}
		printf("%d\n", result);
		memset(visit, 0, sizeof(visit));
		memset(map, 0, sizeof(map));
	}
}
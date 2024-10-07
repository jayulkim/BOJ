#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
int visit[51][51];
int map[51][51];
void dfs(int y, int x, int w, int h)
{
	visit[y][x] = 1;
	if (x + 1 < w && visit[y][x + 1] == 0 && map[y][x + 1] == 1)
	{
		dfs(y, x + 1, w, h);
	}
	if (x - 1 >= 0 && visit[y][x - 1] == 0 && map[y][x - 1] == 1)
	{
		dfs(y, x - 1, w, h);
	}
	if (y + 1 < h && visit[y + 1][x] == 0 && map[y + 1][x] == 1)
	{
		dfs(y + 1, x, w, h);
	}
	if (y - 1 >= 0 && visit[y - 1][x] == 0 && map[y - 1][x] == 1)
	{
		dfs(y - 1, x, w, h);
	}
	if (x + 1 < w && y + 1 < h && visit[y + 1][x + 1] == 0 && map[y + 1][x + 1] == 1)
	{
		dfs(y + 1, x + 1, w, h);
	}
	if (x + 1 < w && y - 1 >= 0 && visit[y - 1][x + 1] == 0 && map[y - 1][x + 1] == 1)
	{
		dfs(y - 1, x + 1, w, h);
	}
	if (x - 1 >= 0 && y + 1 < h && visit[y + 1][x - 1] == 0 && map[y + 1][x - 1] == 1)
	{
		dfs(y + 1, x - 1, w, h);
	}
	if (x - 1 >= 0 && y - 1 >= 0 && visit[y - 1][x - 1] == 0 && map[y - 1][x - 1] == 1)
	{
		dfs(y - 1, x - 1, w, h);
	}
}
int main(void)
{
	while (1)
	{
		int w = 0, h = 0;
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0)
		{
			break;
		}
		for (int j = 0;j < h; j++)
		{
			for (int k = 0;k < w; k++)
			{
				scanf("%d", &map[j][k]);
			}
		}
		int result = 0;
		while (1)
		{
			int count = 0;
			for (int j = 0;j < h; j++)
			{
				for (int k = 0; k < w; k++)
				{
					if (visit[j][k] == 0 && map[j][k] == 1)
					{
						count++;
						dfs(j, k, w, h);
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
	}
}
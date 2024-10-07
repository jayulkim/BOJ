#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int visit[101][101];
int map[101][101];
int ary[101];
int index = 0;
void dfs(int y, int x, int m, int n)
{
	visit[y][x] = 1;
	ary[index]++;
	if (x + 1 < n && visit[y][x + 1] == 0 && map[y][x + 1] == 0)
	{
		dfs(y, x + 1, m, n);
	}
	if (x - 1 >= 0 && visit[y][x - 1] == 0 && map[y][x - 1] == 0)
	{
		dfs(y, x - 1, m, n);
	}
	if (y - 1 >= 0 && visit[y - 1][x] == 0 && map[y - 1][x] == 0)
	{
		dfs(y - 1, x, m, n);
	}
	if (y + 1 < m && visit[y + 1][x] == 0 && map[y + 1][x] == 0)
	{
		dfs(y + 1, x, m, n);
	}
}
int compare(const void* num1, const void* num2)
{
	return *(int*)num1 - *(int*)num2;
}
int main(void)
{
	int m = 0, n = 0, k = 0;
	scanf("%d %d %d", &m, &n, &k);
	for (int i = 0; i < k; i++)
	{
		int x1 = 0;
		int y1 = 0;
		int x2 = 0;
		int y2 = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int j = y1; j < y2; j++)
		{
			for (int k = x1; k < x2; k++)
			{
				map[j][k] = 1;
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
				if (visit[i][j] == 0 && map[i][j] == 0)
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
		index++;
	}
	qsort(ary, index, sizeof(int), compare);
	printf("%d\n", index);
	for (int i = 0; i < index; i++)
	{
		printf("%d ", ary[i]);
	}
}
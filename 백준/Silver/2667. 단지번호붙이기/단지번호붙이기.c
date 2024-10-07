#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
int visit[26][26] = { 0, };
char map[26][26];
int count = 0;
void dfs(int x, int y, int n)
{
	visit[x][y] = 1;
	count++;
	if (map[x + 1][y] == '1' && x + 1 < n && visit[x + 1][y] == 0)
	{
		dfs(x + 1, y, n);
	}
	if (map[x - 1][y] == '1' && x - 1 >= 0 && visit[x - 1][y] == 0)
	{
		dfs(x - 1, y, n);
	}
	if (map[x][y + 1] == '1' && y + 1 < n && visit[x][y + 1] == 0)
	{
		dfs(x, y + 1, n);
	}
	if (map[x][y - 1] == '1' && y - 1 >= 0 && visit[x][y - 1] == 0)
	{
		dfs(x, y - 1, n);
	}
}
int ary[630] = { 0, };
int index1 = 0;
int compare(const void* num1, const void* num2)
{
	return *(int*)num1 - *(int*)num2;
}
int main(void)
{
	int n = 0, result = 0;
	scanf("%d", &n);
	for (int j = 0; j < n; j++)
	{
		scanf(" %s", map[j]);
	}
	while (1)
	{
		int count1 = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (visit[i][j] == 0 && map[i][j] == '1')
				{
					dfs(i, j, n);
					ary[index1++] = count;
					count1++;
					count = 0;
					break;
				}
			}
			if (count1 != 0)
			{
				break;
			}
		}
		if (count1 == 0)
		{
			break;
		}
		result++;
	}
	qsort(ary, index1, sizeof(int), compare);
	printf("%d\n", result);
	for (int j = 0; j < index1; j++)
	{
		printf("%d\n", ary[j]);
	}
}
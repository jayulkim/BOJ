#include <bits/stdc++.h>
using namespace std;
int Map[501][501];
int visited[501][501];
int Max = 0;
int bfs(int y, int x, int n, int m)
{
	int count = 0;
	queue<pair<int, int>>q;
	q.push({ y, x });
	visited[y][x] = 1;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		visited[y][x] = 1;
		count++;
		q.pop();
		if (x - 1 >= 0 && Map[y][x - 1] == 1 && visited[y][x - 1] == 0)
		{
			q.push({ y, x - 1 });
			visited[y][x - 1] = 1;
		}
		if (y - 1 >= 0 && Map[y - 1][x] == 1 && visited[y - 1][x] == 0)
		{
			q.push({ y - 1, x });
			visited[y - 1][x] = 1;
		}
		if (x + 1 < m && Map[y][x + 1] == 1 && visited[y][x + 1] == 0)
		{
			q.push({ y, x + 1 });
			visited[y][x + 1] = 1;
		}
		if (y + 1 < n && Map[y + 1][x] == 1 && visited[y + 1][x] == 0)
		{
			q.push({ y + 1, x });
			visited[y + 1][x] = 1;
		}
	}
	return count;
}
int main(void)
{
	int n = 0, m = 0;
	cin >> n >> m;
	for (int i = 0;i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> Map[i][j];
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j] == 0 && Map[i][j] == 1)
			{
				int count = bfs(i, j, n, m);
				result++;
				if (Max < count)
				{
					Max = count;
				}
			}
		}
	}
	cout << result << '\n' << Max;
}
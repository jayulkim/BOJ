#include <bits/stdc++.h>
using namespace std;
int Map[1001][1001];
int visited[1001][1001];
int result = 0;
queue<pair<int, int>>q1;
queue<pair<int, int>>q2;
void bfs(int n, int m)
{
	int q11 = 1;
	int q22 = 0;
	while (1)
	{
		if (q11 == 1)
		{
			if (!q1.empty())
			{
				while (!q1.empty())
				{
					int y = q1.front().first;
					int x = q1.front().second;
					visited[y][x] = 1;
					q1.pop();
					if (x - 1 >= 0 && Map[y][x - 1] == 0 && visited[y][x - 1] == 0)
					{
						q2.push({ y, x - 1 });
						visited[y][x - 1] = 1;
					}
					if (y - 1 >= 0 && Map[y - 1][x] == 0 && visited[y - 1][x] == 0)
					{
						q2.push({ y - 1, x });
						visited[y - 1][x] = 1;
					}
					if (x + 1 < m && Map[y][x + 1] == 0 && visited[y][x + 1] == 0)
					{
						q2.push({ y, x + 1 });
						visited[y][x + 1] = 1;
					}
					if (y + 1 < n && Map[y + 1][x] == 0 && visited[y + 1][x] == 0)
					{
						q2.push({ y + 1, x });
						visited[y + 1][x] = 1;
					}
				}
				q11 = 0;
				q22 = 1;
				result++;
			}
			else
			{
				return;
			}
		}
		else if (q22 == 1)
		{
			if (!q2.empty())
			{
				while (!q2.empty())
				{
					int y = q2.front().first;
					int x = q2.front().second;
					visited[y][x] = 1;
					q2.pop();
					if (x - 1 >= 0 && Map[y][x - 1] == 0 && visited[y][x - 1] == 0)
					{
						q1.push({ y, x - 1 });
						visited[y][x - 1] = 1;
					}
					if (y - 1 >= 0 && Map[y - 1][x] == 0 && visited[y - 1][x] == 0)
					{
						q1.push({ y - 1, x });
						visited[y - 1][x] = 1;
					}
					if (x + 1 < m && Map[y][x + 1] == 0 && visited[y][x + 1] == 0)
					{
						q1.push({ y, x + 1 });
						visited[y][x + 1] = 1;
					}
					if (y + 1 < n && Map[y + 1][x] == 0 && visited[y + 1][x] == 0)
					{
						q1.push({ y + 1, x });
						visited[y + 1][x] = 1;
					}
				}
				q11 = 1;
				q22 = 0;
				result++;
			}
			else
			{
				return;
			}
		}
	}
}
int main(void)
{
	int n = 0, m = 0;
	cin >> m >> n;
	for (int i = 0;i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == 1)
			{
				q1.push({ i, j });
			}
		}
	}
	bfs(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (Map[i][j] == 0 && visited[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
		}
	}
	cout << result - 1;
	return 0;
}
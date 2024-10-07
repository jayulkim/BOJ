#include <bits/stdc++.h>
using namespace std;
int Map[101][101][101];
int visited[101][101][101];
int result = 0;
struct pos
{
	int z;
	int y;
	int x;
};
queue<pos>q1;
queue<pos>q2;
void bfs(int n, int m, int h)
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
					int z = q1.front().z;
					int y = q1.front().y;
					int x = q1.front().x;
					visited[z][y][x] = 1;
					q1.pop();
					if (x - 1 >= 0 && Map[z][y][x - 1] == 0 && visited[z][y][x - 1] == 0)
					{
						q2.push({ z, y, x - 1 });
						visited[z][y][x - 1] = 1;
					}
					if (y - 1 >= 0 && Map[z][y - 1][x] == 0 && visited[z][y - 1][x] == 0)
					{
						q2.push({ z, y - 1, x });
						visited[z][y - 1][x] = 1;
					}
					if (x + 1 < m && Map[z][y][x + 1] == 0 && visited[z][y][x + 1] == 0)
					{
						q2.push({ z, y, x + 1 });
						visited[z][y][x + 1] = 1;
					}
					if (y + 1 < n && Map[z][y + 1][x] == 0 && visited[z][y + 1][x] == 0)
					{
						q2.push({ z, y + 1, x });
						visited[z][y + 1][x] = 1;
					}
					if (z - 1 >= 0 && Map[z - 1][y][x] == 0 && visited[z - 1][y][x] == 0)
					{
						q2.push({ z - 1, y, x });
						visited[z - 1][y][x] = 1;
					}
					if (z + 1 < h && Map[z + 1][y][x] == 0 && visited[z + 1][y][x] == 0)
					{
						q2.push({ z + 1, y, x });
						visited[z + 1][y][x] = 1;
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
					int z = q2.front().z;
					int y = q2.front().y;
					int x = q2.front().x;
					visited[z][y][x] = 1;
					q2.pop();
					if (x - 1 >= 0 && Map[z][y][x - 1] == 0 && visited[z][y][x - 1] == 0)
					{
						q1.push({ z, y, x - 1 });
						visited[z][y][x - 1] = 1;
					}
					if (y - 1 >= 0 && Map[z][y - 1][x] == 0 && visited[z][y - 1][x] == 0)
					{
						q1.push({z, y - 1, x });
						visited[z][y - 1][x] = 1;
					}
					if (x + 1 < m && Map[z][y][x + 1] == 0 && visited[z][y][x + 1] == 0)
					{
						q1.push({ z, y, x + 1 });
						visited[z][y][x + 1] = 1;
					}
					if (y + 1 < n && Map[z][y + 1][x] == 0 && visited[z][y + 1][x] == 0)
					{
						q1.push({ z, y + 1, x });
						visited[z][y + 1][x] = 1;
					}
					if (z - 1 >= 0 && Map[z - 1][y][x] == 0 && visited[z - 1][y][x] == 0)
					{
						q1.push({ z - 1, y, x });
						visited[z - 1][y][x] = 1;
					}
					if (z + 1 < h && Map[z + 1][y][x] == 0 && visited[z + 1][y][x] == 0)
					{
						q1.push({ z + 1, y, x });
						visited[z + 1][y][x] = 1;
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
	int n = 0, m = 0, h = 0;
	cin >> m >> n >> h;
	for (int k = 0; k < h; k++)
	{
		for (int i = 0;i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> Map[k][i][j];
				if (Map[k][i][j] == 1)
				{
					q1.push({k, i, j });
				}
			}
		}
	}
	bfs(n, m, h);
	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (Map[k][i][j] == 0 && visited[k][i][j] == 0)
				{
					cout << -1;
					return 0;
				}
			}
		}
	}
	cout << result - 1;
	return 0;
}
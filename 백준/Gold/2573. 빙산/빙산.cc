#include <bits/stdc++.h>
using namespace std;
int Map[301][301];
bool visited[301][301];
struct pos
{
	int y;
	int x;
	int minus;
};
queue<pos>q;
int Forward[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
void dfs(int y, int x, int n, int m)
{
	visited[y][x] = true;
	for (int i = 0; i < 4; i++)
	{
		if (Forward[i][0] + y >= 0 && Forward[i][0] + y < n && Forward[i][1] + x >= 0 && Forward[i][1] + x < m && Map[Forward[i][0] + y][Forward[i][1] + x] != 0 && visited[Forward[i][0] + y][Forward[i][1] + x] == false)
		{
			dfs(y + Forward[i][0], x + Forward[i][1], n, m);
		}
	}
}
int main(void)
{
	int n = 0, m = 0;
	cin >> n >> m; 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> Map[i][j];
		}
	}
	int result = 0;
	while (1)
	{
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (Map[i][j] != 0)
				{
					dfs(i, j, n, m);
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
			cout << 0;
			return 0;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (Map[i][j] != 0 && visited[i][j] == false)
				{
					cout << result;
					return 0;
				}
			}
		}
		result++;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (Map[i][j] != 0)
				{
					int temp = 0;
					for (int k = 0; k < 4; k++)
					{
						if (Forward[k][0] + i >= 0 && Forward[k][0] + i < n && Forward[k][1] + j >= 0 && Forward[k][1] + j < m && Map[Forward[k][0] + i][Forward[k][1] + j] == 0)
						{
							if (temp < Map[i][j])
							{
								temp++;
							}
						}
					}
					q.push({ i, j, temp });
				}
			}
		}
		while (!q.empty())
		{
			Map[q.front().y][q.front().x] -= q.front().minus;
			q.pop();
		}
		memset(visited, false, sizeof(visited));
	}
	return 0;
}
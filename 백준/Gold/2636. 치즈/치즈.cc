#include <bits/stdc++.h>
using namespace std;
int Map[101][101];
bool visited[101][101];
struct pos
{
	int y;
	int x;
};
queue<pos>q1;
queue<pos>q2;
int Forward[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
void dfs(int y, int x, int n, int m)
{
	visited[y][x] = true;
	Map[y][x] = 2;
	for (int i = 0; i < 4; i++)
	{
		if (Forward[i][0] + y >= 0 && Forward[i][0] + y <= n + 1 && Forward[i][1] + x >= 0 && Forward[i][1] + x <= m + 1 && Map[Forward[i][0] + y][Forward[i][1] + x] != 1 && visited[Forward[i][0] + y][Forward[i][1] + x] == false)
		{
			dfs(y + Forward[i][0], x + Forward[i][1], n, m);
		}
	}
}
int main(void)
{
	int n = 0, m = 0;
	cin >> n >> m; 
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> Map[i][j];
		}
	}
	int result = 0;
	while (1)
	{
		dfs(0, 0, n, m);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					if (Map[Forward[k][0] + i][Forward[k][1] + j] == 2 && Map[i][j] == 1)
					{
						Map[i][j] = 0;
						q1.push({ i,j });
						break;
					}
				}
			}
		}
		result++;
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (Map[i][j] == 1 && visited[i][j] == false)
				{
					count++;
					break;
				}
			}
		}
		if (count == 0)
		{
			cout << result << '\n' << q1.size();
			return 0;
		}
		queue<pos>().swap(q1);
		memset(visited, false, sizeof(visited));
	}
	return 0;
}
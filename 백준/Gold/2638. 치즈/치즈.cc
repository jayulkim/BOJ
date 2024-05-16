#include <bits/stdc++.h>
using namespace std;
bool visited[101][101];
int Map[101][101];
struct pos
{
	int y;
	int x;
};
void bfs(int y, int x, int n, int m)
{
	queue<pos>q;
	visited[y][x] = true;
	Map[y][x] = 2;
	q.push({ y, x });
	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		visited[y][x] = true;
		Map[y][x] = 2;
		q.pop();
		if (y + 1 < n && visited[y + 1][x] == false && Map[y + 1][x] != 1)
		{
			visited[y + 1][x] = true;
			Map[y + 1][x] = 2;
			q.push({ y + 1,x });
		}
		if (y - 1 >= 0 && visited[y - 1][x] == false && Map[y - 1][x] != 1)
		{
			visited[y - 1][x] = true;
			Map[y - 1][x] = 2;
			q.push({ y - 1,x });
		}
		if (x + 1 < m && visited[y][x + 1] == false && Map[y][x + 1] != 1)
		{
			visited[y][x + 1] = true;
			Map[y][x + 1] = 2;
			q.push({ y,x + 1 });
		}
		if (x - 1 >= 0 && visited[y][x - 1] == false && Map[y][x - 1] != 1)
		{
			visited[y][x - 1] = true;
			Map[y][x - 1] = 2;
			q.push({ y,x - 1 });
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
	vector<pos>v;
	while (1)
	{
		bfs(0, 0, n, m);
		bfs(0, m - 1, n, m);
		bfs(n - 1, 0, n, m);
		bfs(n - 1, m - 1, n, m);
		int stop = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (Map[i][j] == 1)
				{
					stop++;
					int count = 0;
					if (i - 1 >= 0 && Map[i - 1][j] == 2)
					{
						count++;
					}
					if (j - 1 >= 0 && Map[i][j - 1] == 2)
					{
						count++;
					}
					if (i + 1 < n && Map[i + 1][j] == 2)
					{
						count++;
					}
					if (j + 1 < m && Map[i][j + 1] == 2)
					{
						count++;
					}
					if (count >= 2)
					{
						v.push_back({ i, j });
					}
				}
			}
		}
		int end = v.size();
		for (int i = 0; i < end; i++)
		{
			Map[v.back().y][v.back().x] = 2;
			v.pop_back();
		}
		if (stop == 0)
		{
			break;
		}
		result++;
		memset(visited, false, sizeof(visited));
	}
	cout << result;
}
#include <bits/stdc++.h>
using namespace std;
bool visited[9][9];
int Map[9][9];
struct pos
{
	int y;
	int x;
};
queue<pos>q1;
queue<pos>q2;
void bfs(int n, int m)
{
	while (1)
	{
		if (q1.empty() && q2.empty())
		{
			return;
		}
		while (!q1.empty())
		{
			pos temp = q1.front();
			visited[temp.y][temp.x] = true;
			q1.pop();
			if (temp.x + 1 < m && visited[temp.y][temp.x + 1] == false && Map[temp.y][temp.x + 1] == 0)
			{
				q2.push({ temp.y, temp.x + 1 });
				visited[temp.y][temp.x + 1] == true;
			}
			if (temp.x - 1 >= 0 && visited[temp.y][temp.x - 1] == false && Map[temp.y][temp.x - 1] == 0)
			{
				q2.push({ temp.y, temp.x - 1 });
				visited[temp.y][temp.x - 1] == true;
			}
			if (temp.y + 1 < n && visited[temp.y + 1][temp.x] == false && Map[temp.y + 1][temp.x] == 0)
			{
				q2.push({ temp.y + 1, temp.x });
				visited[temp.y + 1][temp.x] == true;
			}
			if (temp.y - 1 >= 0 && visited[temp.y - 1][temp.x] == false && Map[temp.y - 1][temp.x] == 0)
			{
				q2.push({ temp.y - 1, temp.x });
				visited[temp.y - 1][temp.x] == true;
			}
		}
		while (!q2.empty())
		{
			pos temp = q2.front();
			visited[temp.y][temp.x] = true;
			q2.pop();
			if (temp.x + 1 < m && visited[temp.y][temp.x + 1] == false && Map[temp.y][temp.x + 1] == 0)
			{
				q1.push({ temp.y, temp.x + 1 });
				visited[temp.y][temp.x + 1] == true;
			}
			if (temp.x - 1 >= 0 && visited[temp.y][temp.x - 1] == false && Map[temp.y][temp.x - 1] == 0)
			{
				q1.push({ temp.y, temp.x - 1 });
				visited[temp.y][temp.x - 1] == true;
			}
			if (temp.y + 1 < n && visited[temp.y + 1][temp.x] == false && Map[temp.y + 1][temp.x] == 0)
			{
				q1.push({ temp.y + 1, temp.x });
				visited[temp.y + 1][temp.x] == true;
			}
			if (temp.y - 1 >= 0 && visited[temp.y - 1][temp.x] == false && Map[temp.y - 1][temp.x] == 0)
			{
				q1.push({ temp.y - 1, temp.x });
				visited[temp.y - 1][temp.x] == true;
			}
		}
	}
}
int main(void)
{
	int n = 0, m = 0;
	cin >> n >> m;
	vector<pos>v1;
	vector<pos>v2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == 0)
			{
				v1.push_back({ i, j });
			}
			else if (Map[i][j] == 2)
			{
				v2.push_back({ i, j });
			}
		}
	}
	int Max = 0;
	for (int i = 0; i < v1.size() - 2; i++)
	{
		for (int j = i + 1; j < v1.size() - 1; j++)
		{
			for (int k = j + 1; k < v1.size(); k++)
			{
				int result = 0;
				visited[v1[i].y][v1[i].x] = true;
				visited[v1[j].y][v1[j].x] = true;
				visited[v1[k].y][v1[k].x] = true;
				for (auto& l : v2)
				{
					q1.push(l);
				}
				bfs(n, m);
				for (int l = 0; l < n; l++)
				{
					for (int u = 0; u < m; u++)
					{
						if (Map[l][u] == 0 && visited[l][u] == false)
						{
							result++;
						}
					}
				}
				Max = max(Max, result);
				memset(visited, false, sizeof(visited));
			}
		}
	}
	cout << Max;
}
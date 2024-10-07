#include <bits/stdc++.h>
using namespace std;
int Map[501][501];
bool visited[501][501];
int Forward[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0,1} };
int dp[501][501];
int dfs(int y, int x, int n, int m)
{
	if (visited[y][x])
	{
		return dp[y][x];
	}
	for (int i = 0; i < 4; i++)
	{
		if (y + Forward[i][0] >= 0 && y + Forward[i][0] < n && x + Forward[i][1] >= 0 && x + Forward[i][1] < m && Map[y][x] < Map[y + Forward[i][0]][x + Forward[i][1]])
		{
			dp[y][x] += dfs(y + Forward[i][0], x + Forward[i][1], n, m);
		}
	}
	visited[y][x] = true;
	return dp[y][x];
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> Map[i][j];
		}
	}
	dp[0][0] = 1;
	cout << dfs(n - 1, m - 1, n, m);
}
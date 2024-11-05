#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>v(n + 1, vector<int>(4, 0));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= 3; ++j)
		{
			cin >> v[i][j];
		}
	}
	vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(4, vector<int>(4, -1)));
	function<int(int, int, int)> dfs = [&](int start, int pre, int depth)
		{
			if (depth == n)
			{
				int pivot = INT_MAX;
				for (int i = 1; i <= 3; ++i)
				{
					if (i == start || i == pre)
					{
						continue;
					}
					pivot = min(pivot, v[depth][i]);
				}
				return pivot;
			}
			if (dp[depth][pre][start] != -1)
			{
				return dp[depth][pre][start];
			}
			int cost = INT_MAX;
			if (depth == 1)
			{
				cost = min({ cost, dfs(1, 1, 2) + v[1][1], dfs(2,2,2) + v[1][2], dfs(3,3,2) + v[1][3] });
			}
			else
			{
				for (int i = 1; i <= 3; ++i)
				{
					if (i == pre)
					{
						continue;
					}
					cost = min(cost, dfs(start, i, depth + 1) + v[depth][i]);
				}
			}
			return dp[depth][pre][start] = cost;
		};
	cout << dfs(0, 0, 1);
	return 0;
}
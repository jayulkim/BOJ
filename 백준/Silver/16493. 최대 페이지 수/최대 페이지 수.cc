#include <bits/stdc++.h>
using namespace std;
int dp[21][201];
struct info
{
	int cost;
	int worth;
};
int main(void)
{
	int m = 0;
	int n = 0;
	cin >> n >> m;
	vector<info>v(m);
	for (int i = 0; i < m; i++)
	{
		cin >> v[i].cost >> v[i].worth;
	}
	for (int i = 1; i <= n; i++)
	{
		if (v[0].cost <= i)
		{
			dp[0][i] = v[0].worth;
		}
	}
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j - v[i].cost >= 0)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].cost] + v[i].worth);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[m - 1][n];
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
struct info
{
	int count;
	int cost;
};
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<info>v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].cost;
		v[i].count = i + 1;
	}
	for (int i = 1; i <= n; i++)
	{
		if (v[0].count <= i)
		{
			dp[0][i] = v[0].cost * (i - v[0].count + 1);
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j - v[i].count >= 0)
			{
				dp[i][j] = max(max(dp[i - 1][j], dp[i - 1][j - v[i].count] + v[i].cost), dp[i][j - v[i].count] + v[i].cost);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[n - 1][n];
	return 0;
}
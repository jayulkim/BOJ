#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[21][100001];
struct info
{
	ll cost;
	ll worth;
};
int main(void)
{
	ll c = 0;
	int n = 0;
	cin >> c >> n;
	vector<info>v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].cost >> v[i].worth;
	}
	for (int i = 1; i <= 100000; i++)
	{
		if (v[0].cost <= i)
		{
			dp[0][i] = (i / v[0].cost) * v[0].worth;
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= 100000; j++)
		{
			if (j - v[i].cost >= 0)
			{
				dp[i][j] = max(max(dp[i - 1][j - v[i].cost] + v[i].worth, dp[i][j - v[i].cost] + v[i].worth), dp[i - 1][j]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	for (int i = 1; i <= 100000; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dp[j][i] >= c)
			{
				cout << i;
				return 0;
			}
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int dp[101][100001];
struct info
{
	int weight;
	int worth;
};
int main(void)
{
	int n = 0, k = 0;
	cin >> n >> k;
	vector<info>v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].weight >> v[i].worth;
	}
	for (int i = 1; i <= k; i++)
	{
		if (v[0].weight <= i)
		{
			dp[0][i] = v[0].worth;
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j - v[i].weight >= 0)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].weight] + v[i].worth);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[n - 1][k];
}
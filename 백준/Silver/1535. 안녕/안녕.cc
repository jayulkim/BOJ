#include <bits/stdc++.h>
using namespace std;
int dp[21][101];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<int>plus(n);
	vector<int>minus(n);
	for (int i = 0; i < n; i++)
	{
		cin >> minus[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> plus[i];
	}
	for (int i = 1; i <= 100; i++)
	{
		if (minus[0] < i)
		{
			dp[0][i] = plus[0];
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= 100; j++)
		{
			if (j - minus[i] >= 1)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - minus[i]] + plus[i]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[n - 1][100];
}
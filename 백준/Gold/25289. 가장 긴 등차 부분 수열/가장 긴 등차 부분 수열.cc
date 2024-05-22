#include <bits/stdc++.h>
using namespace std;
int dp[101];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int result = 0;
	for (int i = -99; i <= 99; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[j] - i >= 0 && v[j] - i <= 100)
			{
				dp[v[j]] = dp[v[j] - i] + 1;
			}
			else
			{
				dp[v[j]] = 1;
			}
			result = max(result, dp[v[j]]);
		}
		memset(dp, 0, sizeof(dp));
	}
	cout << result;
}
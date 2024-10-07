#include <bits/stdc++.h>
using namespace std;
int dp[501][501];
int ary[501][501];
int main(void)
{
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> ary[i][j];
		}
	}
	dp[0][0] = ary[0][0];
	int result = dp[0][0];
	for (int i = 1; i < n; i++)
	{
		dp[i][0] = dp[i - 1][0] + ary[i][0];
		result = max(result, dp[i][0]);
		dp[i][i] = dp[i - 1][i - 1] + ary[i][i];
		result = max(result, dp[i][i]);
		for (int j = 1; j < i; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + ary[i][j];
			result = max(result, dp[i][j]);
		}
	}
	cout << result;
}
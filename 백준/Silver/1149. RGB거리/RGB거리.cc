#include <bits/stdc++.h>
using namespace std;
int dp[1001][3];
int ary[1001][3];
int main(void)
{
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ary[i][0] >> ary[i][1] >> ary[i][2];
	}
	dp[0][0] = ary[0][0];
	dp[0][1] = ary[0][1];
	dp[0][2] = ary[0][2];
	for (int i = 1; i < n; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + ary[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + ary[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + ary[i][2];
	}
	cout << min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
}
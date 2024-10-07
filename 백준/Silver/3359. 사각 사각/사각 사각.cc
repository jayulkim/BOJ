#include <bits/stdc++.h>
using namespace std;
int dp[1001][2];
int ary[1001][2];
int main(void)
{
	int n = 0; 
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ary[i][0] >> ary[i][1];
	}
	dp[0][1] = ary[0][1];
	dp[0][0] = ary[0][0];
	for (int i = 1; i < n; i++)
	{
		dp[i][0] = max(dp[i - 1][0] + abs(ary[i - 1][1] - ary[i][1]), dp[i - 1][1] + abs(ary[i - 1][0] - ary[i][1])) + ary[i][0];
		dp[i][1] = max(dp[i - 1][0] + abs(ary[i - 1][1] - ary[i][0]), dp[i - 1][1] + abs(ary[i - 1][0] - ary[i][0])) + ary[i][1];
	}
	cout << max(dp[n - 1][0], dp[n - 1][1]);
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[201][201];
int main(void)
{
	for (int i = 1; i <= 200; i++)
	{
		dp[i][1] = 1;
	}
	for (ll i = 1; i <= 200; i++)
	{
		dp[1][i] = i;
	}
	for (int i = 2; i <= 200; i++)
	{
		for (int j = 2; j <= 200; j++)
		{
			dp[i][j] = ((dp[i - 1][j] % 1000000000) + (dp[i][j - 1] % 1000000000)) % 1000000000;
		}
	}
	int n = 0, k = 0;
	cin >> n >> k;
	cout << dp[n][k] % 1000000000;
}


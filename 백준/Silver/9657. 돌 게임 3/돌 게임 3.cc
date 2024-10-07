#include <bits/stdc++.h>
using namespace std;
int dp[1001];
int main(void)
{
	dp[1] = 1;
	dp[2] = -1;
	dp[3] = 1;
	dp[4] = 1;
	int n = 0;
	cin >> n;
	for (int i = 5; i <= n; i++)
	{
		if (dp[i - 4] == -1 || dp[i - 3] == -1 || dp[i - 1] == -1)
		{
			dp[i] = 1;
		}
		else
		{
			dp[i] = -1;
		}
	}
	if (dp[n] == 1)
	{
		cout << "SK";
	}
	else
	{
		cout << "CY";
	}
}
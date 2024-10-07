#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str1 = "";
	string str2 = "";
	cin >> str1;
	cin >> str2;
	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] == str2[0])
		{
			for (int j = i; j < str1.length(); j++)
			{
				dp[0][j] = 1;
			}
			break;
		}
	}
	for (int i = 1; i < str2.length(); i++)
	{
		if (str1[0] == str2[i])
		{
			for (int j = i; j < str2.length(); j++)
			{
				dp[j][0] = 1;
			}
			break;
		}
	}
	for (int i = 1; i < str2.length(); i++)
	{
		for (int j = 1; j < str1.length(); j++)
		{
			if (str2[i] == str1[j])
			{
				dp[i][j] = max(max(dp[i - 1][j - 1] + 1, dp[i - 1][j]), dp[i][j - 1]);
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[str2.length() - 1][str1.length() - 1];
	return 0;
}
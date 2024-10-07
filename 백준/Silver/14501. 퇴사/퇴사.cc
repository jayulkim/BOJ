#include <bits/stdc++.h>
using namespace std;
struct info
{
	int start;
	int end;
	int worth;
};
int dp[16];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<info>v(n + 1);
	v[0].start = 0;
	v[0].end = 0;
	v[0].worth = 0;
	for (int i = 1; i <= n; i++)
	{
		int num = 0;
		cin >> num >> v[i].worth;
		v[i].start = i;
		v[i].end = i + num;
	}
	for (int i = 1; i <= n; i++)
	{
		int Max = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (v[i].end <= n + 1 && v[j].end <= n + 1 && v[i].start >= v[j].end)
			{
				Max = max(Max, dp[j]);
			}
		}
		if (v[i].end <= n + 1)
		{
			dp[i] = Max + v[i].worth;
		}
	}
	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		result = max(result, dp[i]);
	}
	cout << result;
	return 0;
}
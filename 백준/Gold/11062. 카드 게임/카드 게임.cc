#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int  T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<int>v(n + 1, 0);
		for (int i = 1; i <= n; ++i)
		{
			cin >> v[i];
		}
		vector<vector<ll>>dp(n + 1, vector<ll>(n + 1, -1));
		function<ll(int, int)> dfs = [&](int left, int right)
			{
				if (left > right)
				{
					return 0LL;
				}
				if (dp[left][right] != -1)
				{
					return dp[left][right];
				}
				ll cost = 0;
				cost = max(cost, min(dfs(left + 1, right - 1), dfs(left + 2, right)) + v[left]);
				cost = max(cost, min(dfs(left, right - 2), dfs(left + 1, right - 1)) + v[right]);
				return dp[left][right] = cost;
			};
		cout << dfs(1, n) << '\n';
	}
	return 0;
}
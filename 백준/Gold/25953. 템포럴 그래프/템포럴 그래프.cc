#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
typedef tuple<ll, ll, ll>tl;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	ll n = 0, t = 0, m = 0, sx = 0, sy = 0;
	cin >> n >> t >> m >> sx >> sy;
	vector<pll>dp(n + 1, make_pair(-1, LLONG_MAX)); // 시간, 거리
	dp[sx] = make_pair(0, 0);
	auto check = [&](ll a, ll b, ll c, int i )
		{
			if (dp[a].second == LLONG_MAX || dp[a].first == i || dp[a].first == -1)
			{
				return;
			}
			if (dp[b].second > dp[a].second + c)
			{
				dp[b].second = dp[a].second + c;
				dp[b].first = i;
			}
		};
	for (int i = 1; i <= t; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			ll a = 0, b = 0, c = 0;
			cin >> a >> b >> c;
			check(a, b, c, i);
			check(b, a, c, i);
		}
	}
	if (dp[sy].second == LLONG_MAX)
	{
		cout << -1;
		return 0;
	}
	cout << dp[sy].second;
	return 0;
}
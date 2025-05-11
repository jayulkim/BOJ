#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll> lll;
typedef tuple<pll, string, ll> pllsl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	ll sum = 0;
	vector<pll>v(n + 1);
	vector<vector<ll>>dp(n + 1, vector<ll>(m + 1));
	for (int i = 1; i <= n; i++) {
		cin >> v[i].first >> v[i].second;
		sum += v[i].second;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j - v[i].first >= 0) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].first] + v[i].second);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << sum - dp[n][m];
	return 0;
}
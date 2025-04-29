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
	if (!m) {
		cout << 0;
		return 0;
	}
	vector<ll>v(n + 1);
	vector<vector<ll>>dp(n + 1, vector<ll>(m + 1, LLONG_MAX));
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		vector<ll>temp(m + 1, LLONG_MAX);
		for (int j = 1; j <= m; j++) {
			if (dp[i - 1][j] != LLONG_MAX) {
				temp[j] = min(temp[j], dp[i - 1][j]);
			}
			if (j >= v[i] && dp[i - 1][j - v[i]] != LLONG_MAX) {
				temp[j] = min(temp[j], dp[i - 1][j - v[i]] + 1);
			}
			if (j == v[i]) {
				temp[j] = 1;
			}
		}
		dp[i] = temp;
	}
	ll Min = LLONG_MAX;
	for (int i = 1; i <= n; i++) {
		Min = min(Min, dp[i][m]);
	}
	if (Min == LLONG_MAX) {
		cout << -1;
		return 0;
	}
	cout << Min;
	return 0;
}
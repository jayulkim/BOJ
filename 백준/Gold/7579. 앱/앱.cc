#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll dp[101][10001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<pll>v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i].first;
	}
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> v[i].second;
		sum += v[i].second;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (j - v[i].second >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i].second] + v[i].first);
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			}
			else {
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			}
		}
	}
	ll Min = LLONG_MAX;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (dp[i][j] >= m) {
				Min = min(Min, (ll)j);
			}
		}
	}
	cout << Min;
	return 0;
}
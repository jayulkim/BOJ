#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n = 0;
vector<pll>v;
vector<vector<ll>>dp(501, vector<ll>(501, -1));
ll dfs(ll left, ll right) {
	if (left == right) {
		return 0;
	}
	if (dp[left][right] != -1) {
		return dp[left][right];
	}
	ll weight = LLONG_MAX;
	for (int i = left; i < right; i++) {
		weight = min(weight, dfs(left, i) + dfs(i + 1, right) + v[left].first * v[i].second * v[right].second);
	}
	return dp[left][right] = weight;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		v.push_back({ a, b });
	}
	cout << dfs(0, n - 1);
	return 0;
}
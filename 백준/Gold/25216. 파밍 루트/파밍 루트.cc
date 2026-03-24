#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;
ll dp[5001][101];
llll v[5001];
vector<vector<ll>>graph(5001);
ll dfs(ll a, ll b, ll mid) {
	if (b == k) {
		return 0;
	}
	if (dp[a][b] != -1) {
		return dp[a][b];
	}
	ll weight = 0;
	if (!mid) {
		for (auto& i : graph[a]) {
			weight = max(weight, dfs(i, b + 1, mid) + get<3>(v[i]));
		}
	}
	else {
		for (auto& i : graph[a]) {
			auto [c, d, e, f] = v[i];
			if (!max((ll)0, c + d * b - e * mid)) {
				weight = max(weight, dfs(i, b + 1, mid) + get<3>(v[i]));
			}
		}
	}
	return dp[a][b] = weight;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		ll a = 0, b = 0, c = 0, d = 0;
		cin >> a >> b >> c >> d;
		v[i] = { a, b, c, d };
	}
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	memset(dp, -1, sizeof(dp));
	ll Max = dfs(1, 1, 0) + get<3>(v[1]);
	ll start = 1, end = 1e10, mid = 0;
	ll result = LLONG_MAX;
	while (start <= end) {
		mid = (start + end) / 2;
		memset(dp, -1, sizeof(dp));
		auto [a, b, c, d] = v[1];
		if (dfs(1, 1, mid) + get<3>(v[1]) == Max && a - c * mid <= 0) {
			end = mid - 1;
			result = min(result, mid);
		}
		else {
			start = mid + 1;
		}
	}
	cout << result;
	return 0;
}
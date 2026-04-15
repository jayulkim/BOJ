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

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<vector<ll>>graph(n + 1);
	for (int i = 0; i < n - 1; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<ll>v(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<ll>dp(1 << n, -1);
	function<ll(ll)> dfs = [&](ll a) -> ll {
		ll count = 0;
		for (int i = 0; i < n; i++) {
			if ((a >> i) & 1 && v[i] == 1) {
				count++;
			}
		}
		if (count > m) {
			return -1e9;
		}
		if (dp[a] != -1) {
			return dp[a];
		}
		ll weight = 0;
		for (int i = 0; i < n; i++) {
			if ((a >> i) & 1) {
				for (auto& j : graph[i]) {
					if (!((a >> j) & 1)) {
						if (v[j] == 2) {
							weight = max(weight, dfs(a | (1 << j)) + 1);
						}
						weight = max(weight, dfs(a | (1 << j)));
					}
				}
			}
		}
		return dp[a] = weight;
		};
	ll result = dfs(1);
	if (v[0] == 2) {
		result++;
	}
	cout << result;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>graph[100001];
vector<bool>dp(100001, false);
bool dfs(ll parent, ll node) {
	if (graph[node].size() == 1 && node != 1) {
		return dp[node] = true;
	}
	bool find = false;
	for (auto& i : graph[node]) {
		if (parent != i) {
			if (dfs(node, i)) {
				find = true;
			}
		}
	}
	return dp[node] = !find;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		ll start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	dfs(-1, 1);
	for (int i = 1; i <= n; i++) {
		if (!dp[i]) {
			cout << "donggggas" << '\n';
		}
		else {
			cout << "uppercut" << '\n';
		}
	}
	return 0;
}
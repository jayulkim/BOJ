#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>dp(1001, -1);
vector<pll>graph[1001];
ll dfs(ll parent, ll node) {
	if (dp[node] != -1) {
		return dp[node];
	}
	if (graph[node].size() == 1) {
		return graph[node][0].second;
	}
	ll a = 0;
	for (auto& i : graph[node]) {
		if (i.first != parent) {
			a += min(dfs(node, i.first), i.second);
		}
	}
	return dp[node] = a;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	while (num--) {
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			ll a = 0, b = 0, c = 0;
			cin >> a >> b >> c;
			graph[a].push_back({ b, c });
			graph[b].push_back({ a, c });
		}
		ll Min = 0;
		for (auto& i : graph[1]) {
			Min += min(dfs(1, i.first), i.second);
		}
		cout << Min << '\n';
		for (int i = 1; i <= n; i++) {
			vector<pll>().swap(graph[i]);
		}
		vector<ll>(1001, -1).swap(dp);
	}
	return 0;
}
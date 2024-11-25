#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<vector<ll>>dp(1001, vector<ll>(1001, -1));
vector<ll>graph[1001];
vector<ll>cost(1001, -1);
ll dfs(ll parent, ll node, ll sp) {
	if (dp[node][sp] != -1) {
		return dp[node][sp];
	}
	ll a = cost[node] - cost[sp], b = cost[node];
	for (auto& i : graph[node]) {
		if (i != parent) {
			a += dfs(node, i, sp);
			b += dfs(node, i, node);
		}
	}
	return dp[node][sp] = min(a, b);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		ll num = 0;
		cin >> num;
		cost[i] = num;
	}
	for (int i = 0; i < n - 1; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	cout << dfs(-1, m, m) + cost[m];
	return 0;
}
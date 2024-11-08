#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n = 0;
vector<ll>graph[1000001];
vector<vector<ll>>dp(1000001, vector<ll>(2, -1));
ll dfs(ll parent, ll node, ll on) {
	if (dp[node][on] != -1) {
		return dp[node][on];
	}
	ll weight = 0;
	if (on) {
		weight++;
		for (auto& i : graph[node]) {
			if (parent != i) {
				weight += min(dfs(node, i, 0), dfs(node, i, 1));
			}
		}
	}
	else {
		for (auto& i : graph[node]) {
			if (parent != i) {
				weight += dfs(node, i, 1);
			}
		}
	}
	return dp[node][on] = weight;
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
	cout << min(dfs(-1, 1, 0), dfs(-1, 1, 1));
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>graph[100001];
vector<ll>dp(100001, -1);
bool visited[100001];
ll parent[100001];
bool notleaf[100001];
map<vector<ll>, ll>Map;
void maketree(ll x) {
	visited[x] = true;
	for (auto& i : graph[x]) {
		if (!visited[i]) {
			parent[i] = x;
			maketree(i);
		}
	}
}
ll dfs(ll node) {
	if (visited[node]) {
		return 0;
	}
	visited[node] = true;
	ll cost = 0;
	for (auto& i : graph[node]) {
		if (!notleaf[i]) {
			cost += Map[{i, parent[i]}];
		}
		else {
			cost += dfs(i);
		}
	}
	return dp[node] = min(cost, Map[{node, parent[node]}]);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < n - 1; i++) {
		ll start = 0, end = 0, weight = 0;
		cin >> start >> end >> weight;
		graph[start].push_back(end);
		graph[end].push_back(start);
		Map[{start, end}] = weight;
		Map[{end, start}] = weight;
	}
	maketree(1);
	Map[{1, 1}] = LLONG_MAX;
	for (int i = 1; i <= n; i++) {
		notleaf[parent[i]] = true;
	}
	memset(visited, false, sizeof(visited));
	cout << dfs(1);
	return 0;
}
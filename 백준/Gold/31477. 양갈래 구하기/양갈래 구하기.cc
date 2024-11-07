#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<pll>graph[100001];
bool visited[100001];
ll dfs(ll node) {
	visited[node] = true;
	if (graph[node].size() == 1) {
		return graph[node][0].second;
	}
	ll cost = 0;
	for (auto& i : graph[node]) {
		if (!visited[i.first]) {
			cost += min(dfs(i.first), i.second);
		}
	}
	return cost;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		ll start = 0, end = 0, weight = 0;
		cin >> start >> end >> weight;
		graph[start].push_back({ end, weight });
		graph[end].push_back({ start, weight });
	}
	ll result = 0;
	visited[1] = true;
	for (auto& i : graph[1]) {
		result += min(dfs(i.first), i.second);
	}
	cout << result;
	return 0;
}
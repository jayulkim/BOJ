#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll dist[20001];
vector<pll>graph[20001];
vector<ll>result;
ll parent[20001];
ll temp = -1;
void getparent(ll x) {
	if (x == temp) {
		result.push_back(x);
		return;
	}
	result.push_back(x);
	getparent(parent[x]);
}
bool visited[20001];
void dfs(ll start) {
	if (visited[start]) {
		temp = start;
		return;
	}
	visited[start] = true;
	dfs(parent[start]);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		ll start = 0, end = 0, weight = 0;
		cin >> start >> end >> weight;
		graph[start].push_back({ end, weight });
	}
	for (int i = 0; i < n; i++) {
		dist[i] = LLONG_MAX;
	}
	dist[k] = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n; j++) {
			if (dist[j] != LLONG_MAX) {
				for (auto& [a, b] : graph[j]) {
					if (dist[a] > dist[j] + b) {
						dist[a] = dist[j] + b;
						parent[a] = j;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (dist[i] != LLONG_MAX) {
			for (auto& [a, b] : graph[i]) {
				if (dist[a] > dist[i] + b) {
					dfs(a);
					result.push_back(temp);
					getparent(parent[temp]);
					cout << "CYCLE" << '\n';
					cout << result.size() - 1 << '\n';
					reverse(result.begin(), result.end());
					for (auto& i : result) {
						cout << i << ' ';
					}
					return 0;
				}
			}
		}
	}
	cout << "PATH" << '\n';
	for (int i = 0; i < n; i++) {
		cout << dist[i] << ' ';
	}
	return 0;
}
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
vector<ll>graph[100001];
ll dist[100001];
bool visited[100001];
void dfs(ll start, ll count) {
	visited[start] = true;
	dist[start] = count;
	for (auto& i : graph[start]) {
		if (!visited[i]) {
			dfs(i, count + 1);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		dist[i] = LLONG_MAX;
	}
	for (int i = 0; i < m; i++) {
		ll start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end(), greater<ll>());
	}
	dfs(k, 0);
	for (int i = 1; i <= n; i++) {
		if (dist[i] == LLONG_MAX) {
			cout << -1 << '\n';
		}
		else {
			cout << dist[i] << '\n';
		}
	}
	return 0;
}
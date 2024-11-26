#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>graph[100001];
vector<ll>dist(100001);
bool visited[100001];
void dfs(ll start, ll depth) {
	dist[start] = depth;
	visited[start] = true;
	for (auto& i : graph[start]) {
		if (!visited[i]) {
			dfs(i, depth + 1);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(k, 0);
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			cout << -1 << '\n';
		}
		else {
			cout << dist[i] << '\n';
		}
	}
	return 0;
}
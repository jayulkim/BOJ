#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
ll n = 0, m = 0;
vector<pll>graph[501];
ll dist[501];
bool Find = false;
void bellmanford(ll start) {
	for (int i = 1; i <= n; i++) {
		dist[i] = LLONG_MAX;
	}
	dist[start] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (auto& k : graph[j]) {
				if (dist[j] != LLONG_MAX && dist[k.first] > dist[j] + k.second) {
					dist[k.first] = dist[j] + k.second;
					if (i == n) {
						Find = true;
						return;
					}
				}
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll start = 0, end = 0, weight = 0;
		cin >> start >> end >> weight;
		graph[start].push_back({ end, weight });
	}
	bellmanford(1);
	if (Find) {
		cout << -1;
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		if (dist[i] == LLONG_MAX) {
			cout << -1 << '\n';
		}
		else {
			cout << dist[i] << '\n';
		}
	}
	return 0;
}
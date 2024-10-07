#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
ll dist[501];
ll n = 0, m = 0, k = 0;
vector<pll>graph[501];
bool Find = false;
void bellmanford() {
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
	ll num = 0;
	cin >> num;
	while (num--) {
		cin >> n >> m >> k;
		for (int i = 0; i < m; i++) {
			ll start = 0, end = 0, weight = 0;
			cin >> start >> end >> weight;
			graph[start].push_back({ end, weight });
			graph[end].push_back({ start, weight });
		}
		for (int i = 0; i < k; i++) {
			ll start = 0, end = 0, weight = 0;
			cin >> start >> end >> weight;
			graph[start].push_back({ end, -weight });
		}
		bellmanford();
		if (Find) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
		Find = false;
		for (int i = 1; i <= n; i++) {
			vector<pll>().swap(graph[i]);
		}
	}
	return 0;
}
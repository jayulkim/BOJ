#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<pll>graph[10001];
vector<ll>dist(10001, LLONG_MAX);
priority_queue<pll, vector<pll>, greater<pll>>pq;
void dijkstra(ll start) {
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		pll temp = pq.top();
		pq.pop();
		if (dist[temp.second] >= temp.first) {
			for (auto& i : graph[temp.second]) {
				if (dist[i.second] > dist[temp.second] + i.first) {
					dist[i.second] = dist[temp.second] + i.first;
					pq.push({ dist[i.second], i.second });
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
		graph[i].push_back({ 1, i + 1 });
	}
	for (int i = 0; i < n; i++) {
		ll start = 0, end = 0, weight = 0;
		cin >> start >> end >> weight;
		graph[start].push_back({ weight, end });
	}
	dijkstra(0);
	ll Min = m;
	cout << min(Min, dist[m]);
	return 0;
}
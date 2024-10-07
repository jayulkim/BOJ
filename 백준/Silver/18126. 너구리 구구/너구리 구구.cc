#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll dist[5001];
vector<pair<ll, ll>>graph[5001];
ll n = 0;
void dijkstra(ll start) {
	for (int i = 1; i <= n; i++) {
		dist[i] = 987654321000000000;
	}
	dist[start] = 0;
	priority_queue < pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		pair<ll, ll>temp = pq.top();
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
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		ll start = 0, end = 0, weight = 0;
		cin >> start >> end >> weight;
		graph[start].push_back({ weight, end });
		graph[end].push_back({ weight, start });
	}
	dijkstra(1);
	ll Max = 0;
	for (int i = 1; i <= n; i++) {
		Max = max(Max, dist[i]);
	}
	cout << Max;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll, ll>>graph[10001];
ll n = 0;
ll dist[10001];
void bfs(ll start) {
	dist[start] = 0;
	queue<pair<ll, ll>>q;
	q.push({ start, 0 });
	while (!q.empty()) {
		pair<ll, ll>temp = q.front();
		q.pop();
		for (auto& i : graph[temp.first]) {
			if (!dist[i.first] && i.first != start) {
				dist[i.first] = dist[temp.first] + i.second;
				q.push({ i.first, dist[i.first] });
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
		graph[start].push_back({ end, weight });
		graph[end].push_back({ start, weight });
	}
	bfs(1);
	ll k = 0, Max = 0;
	for (int i = 1; i <= n; i++) {
		if (Max < dist[i]) {
			k = i;
			Max = dist[i];
		}
	}
	memset(dist, 0, sizeof(dist));
	bfs(k);
	Max = 0;
	for (int i = 1; i <= n; i++) {
		Max = max(Max, dist[i]);
	}
	cout << Max;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dist[1001];
ll parent[1001];
ll n = 0, m = 0;
vector<pair<ll, ll>>graph[1001];
bool Map[1001][1001];
priority_queue < pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;
void dijkstra(ll start, bool find) {
	for (int i = 1; i <= n; i++) {
		dist[i] = 987654321;
	}
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		pair<ll, ll>temp = pq.top();
		pq.pop();
		if (dist[temp.second] >= temp.first) {
			for (auto& i : graph[temp.second]) {
				if (dist[i.second] > dist[temp.second] + i.first && Map[temp.second][i.second]) {
					dist[i.second] = dist[temp.second] + i.first;
					pq.push({ dist[i.second], i.second });
					if (find) {
						parent[i.second] = temp.second;
					}
				}
			}
		}
	}
}
ll Max = 0;
void dfs(ll x) {
	if (x == 1) {
		return;
	}
	Map[x][parent[x]] = false;
	Map[parent[x]][x] = false;
	dijkstra(1, false);
	Max = max(Max, dist[n]);
	Map[x][parent[x]] = true;
	Map[parent[x]][x] = true;
	dfs(parent[x]);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll start = 0, end = 0, weight = 0;
		cin >> start >> end >> weight;
		graph[start].push_back({ weight, end });
		graph[end].push_back({ weight, start });
		Map[start][end] = true;
		Map[end][start] = true;
	}
	dijkstra(1, true);
	dfs(n);
	cout << Max;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dist[501];
vector<ll>result[501];
ll n = 0, m = 0, a = 0, b = 0;
vector<pair<ll, ll>>graph[501];
bool Map[501][501];
priority_queue <pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;
void dijkstra(ll start) {
	for (int i = 0; i < n; i++) {
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
					vector<ll>().swap(result[i.second]);
					result[i.second].push_back(temp.second);
				}
				else if (dist[i.second] == dist[temp.second] + i.first && Map[temp.second][i.second]) {
					result[i.second].push_back(temp.second);
				}
			}
		}
	}
}
void bfs(ll start) {
	queue<ll>q;
	q.push(start);
	while (!q.empty()) {
		ll temp = q.front();
		q.pop();
		if (temp != a) {
			for (auto& i : result[temp]) {
				if (Map[i][temp]) {
					Map[i][temp] = false;
					q.push(i);
				}
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		cin >> n >> m;
		if (n == 0, m == 0) {
			return 0;
		}
		cin >> a >> b;
		for (int i = 0; i < m; i++) {
			ll start = 0, end = 0, weight = 0;
			cin >> start >> end >> weight;
			graph[start].push_back({ weight, end });
			Map[start][end] = true;
		}
		dijkstra(a);
		bfs(b);
		bool find = false;
		for (int i = 1; i < n; i++) {
			if (Map[a][i]) {
				find = true;
				break;
			}
		}
		if (!find) {
			cout << -1 << '\n';
		}
		else {
			dijkstra(a);
			if (dist[b] == 987654321) {
				cout << -1 << '\n';
			}
			else {
				cout << dist[b] << '\n';
			}
		}
		for (int i = 0; i < n; i++) {
			vector<ll>().swap(result[i]);
			vector<pair<ll, ll>>().swap(graph[i]);
		}
		memset(Map, false, sizeof(Map));
	}
	return 0;
}
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
int dist[501];
vector<pair<int, int>>graph[501];
bool visited[501][501];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
int n = 0, m = 0, k = 0;
void dijkstra(int start) {
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		pair<int, int>temp = pq.top();
		pq.pop();
		if (dist[temp.second] >= temp.first) {
			for (auto& i : graph[temp.second]) {
				if (visited[temp.second][i.second] && dist[i.second] > dist[temp.second] + i.first) {
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
		int start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back({ 1, end });
		graph[end].push_back({ 1, start });
		visited[start][end] = true;
		visited[end][start] = true;
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int command = 0, start = 0, end = 0;
		cin >> command >> start >> end;
		if (command == 1) {
			graph[start].push_back({ 1, end });
			graph[end].push_back({ 1, start });
			visited[start][end] = true;
			visited[end][start] = true;
		}
		else {
			visited[start][end] = false;
			visited[end][start] = false;
		}
		dijkstra(1);
		for (int i = 1; i <= n; i++) {
			if (dist[i] == INF) {
				cout << -1 << ' ';
			}
			else {
				cout << dist[i] << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<int, int>>graph[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
int dist[1001];
int n = 0, m = 0;
void dijkstra(int start) {
	for (int i = 1; i <= n; i++) {
		dist[i] = 987654321;
	}
	pq.push({ 0, start });
	dist[start] = 0;
	while (!pq.empty()) {
		pair<int, int>temp = pq.top();
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
	for (int i = 0; i < n - 1; i++) {
		int start = 0, end = 0, weight = 0;
		cin >> start >> end >> weight;
		graph[start].push_back({ weight, end });
		graph[end].push_back({ weight, start });
	}
	for (int i = 0; i < m; i++) {
		int start = 0, end = 0;
		cin >> start >> end;
		dijkstra(start);
		cout << dist[end] << '\n';
	}
	return 0;
}
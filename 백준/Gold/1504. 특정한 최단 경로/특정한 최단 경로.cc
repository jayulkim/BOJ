#include <bits/stdc++.h>
#define INF 200000005
typedef long long ll;
using namespace std;
ll dist[801];
vector<pair<int, int>>graph[801];
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
void dijkstra(int start) {
	for (int i = 1; i <= 800; i++) {
		dist[i] = INF;
	}
	dist[start] = 0;
	pq.push({ 0, start });
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
	int n = 0, m = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int start = 0, end = 0, weight = 0;
		cin >> start >> end >> weight;
		graph[start].push_back({ weight, end });
		graph[end].push_back({ weight, start });
	}
	int v1 = 0, v2 = 0;
	cin >> v1 >> v2;
	ll result1 = 0, result2 = 0;
	dijkstra(1);
	result1 += dist[v1];
	dijkstra(v1);
	result1 += dist[v2];
	dijkstra(v2);
	result1 += dist[n];
	dijkstra(1);
	result2 += dist[v2];
	dijkstra(v2);
	result2 += dist[v1];
	dijkstra(v1);
	result2 += dist[n];
	if (result1 >= INF && result2 >= INF) {
		cout << -1;
		return 0;
	}
	cout << min(result1, result2);
	return 0;
}
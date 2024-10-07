#include <bits/stdc++.h>
#define INF 1111987654321
using namespace std;
typedef long long ll;
ll dist[100001];
vector<pair<int, int>>graph[100001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
void dijkstra(int start) {
	for (int i = 0; i <= 100000; i++) {
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
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	v[n - 1] = 0;
	for (int i = 0; i < m; i++) {
		int start = 0, end = 0, weight = 0;
		cin >> start >> end >> weight;
		if (v[start] == 0 && v[end] == 0) {
			graph[start].push_back({ weight, end });
			graph[end].push_back({ weight, start });
		}
	}
	dijkstra(0);
	if (dist[n - 1] == INF) {
		cout << -1;
		return 0;
	}
	cout << dist[n - 1];
 	return 0;
}
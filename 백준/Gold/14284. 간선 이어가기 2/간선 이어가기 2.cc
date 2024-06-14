#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
typedef long long ll;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
ll dist[5001];
vector<pair<int, int>>graph[5001];
void dijkstra(int start) {
	for (int i = 1; i <= 5000; i++) {
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int start = 0, end = 0, weight = 0;
		cin >> start >> end >> weight;
		graph[start].push_back({ weight, end });
		graph[end].push_back({ weight, start });
	}
	int start = 0, end = 0;
	cin >> start >> end;
	dijkstra(start);
	cout << dist[end];
	return 0;
}
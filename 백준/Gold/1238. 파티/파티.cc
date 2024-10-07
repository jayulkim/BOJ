#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;
ll dist[1001];
vector<pair<int, int>>graph[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
void dijkstra(int start) {
	for (int i = 1; i <= 1000; i++) {
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
ll result[1001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0, x = 0;
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		int start = 0, end = 0, weight = 0;
		cin >> start >> end >> weight;
		graph[start].push_back({ weight, end });
	}
	ll solve = 0;
	for (int i = 1; i <= n; i++) {
		dijkstra(i);
		result[i] = dist[x];
	}
	for (int i = 1; i <= n; i++) {
		dijkstra(x);
		result[i] += dist[i];
		solve = max(solve, result[i]);
	}
	cout << solve;
	return 0;
}
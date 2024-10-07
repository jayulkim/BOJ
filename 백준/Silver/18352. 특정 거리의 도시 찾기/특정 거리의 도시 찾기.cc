#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
typedef long long ll;
ll dist[300001];
vector<pair<int, int>>graph[300001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
void dijkstra(int start, int n) {
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
				if (dist[i.second] > i.first + dist[temp.second]) {
					dist[i.second] = i.first + dist[temp.second];
					pq.push({ dist[i.second], i.second });
				}
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0, k = 0, x = 0;
	cin >> n >> m >> k >> x;
	for (int i = 0; i < m; i++) {
		int start = 0, end = 0, weight = 0;
		cin >> start >> end;
		graph[start].push_back({ 1, end });
	}
	dijkstra(x, n);
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[i] == k) {
			cout << i << '\n';
			count++;
		}
	}
	if (count == 0) {
		cout << -1;
	}
	return 0;
}
#include <bits/stdc++.h>
#define INF 19876543210
using namespace std;
typedef long long ll;
ll dist[10001];
bool visited[10001];
vector<pair<int, int>>graph[10001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
void dijkstra(int start) {
	for (int i = 1; i <= 10000; i++) {
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
	int num = 0;
	cin >> num;
	while (num--) {
		int n = 0, m = 0, start = 0;
		cin >> n >> m >> start;
		for (int i = 0; i < m; i++) {
			int start = 0, end = 0, weight = 0;
			cin >> start >> end >> weight;
			graph[end].push_back({ weight, start });
		}
		int count = 0;
		dijkstra(start);
		ll Max = 0;
		for (int i = 1; i <= n; i++) {
			if (dist[i] != INF) {
				count++;
				Max = max(Max, dist[i]);
			}
		}
		cout << count << ' ' << Max << '\n';
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= 10000; i++) {
			vector<pair<int, int>>().swap(graph[i]);
		}
	}
 	return 0;
}
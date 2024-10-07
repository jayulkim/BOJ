#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
int dist[5001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
vector<pair<int, int>>graph[5001];
vector<int>result[5001];
int n = 0, m = 0, k = 0, dis = 0, Min = 0;
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
				if (dist[i.second] > dist[temp.second] + i.first) {
					vector<int>().swap(result[temp.second]);
					vector<int>().swap(result[i.second]);
					dist[i.second] = dist[temp.second] + i.first;
					result[temp.second].push_back(i.second);
					result[i.second].push_back(temp.second);
					pq.push({ dist[i.second], i.second });
				}
				else if (dist[i.second] == dist[temp.second] + i.first) {
					result[temp.second].push_back(i.second);
					result[i.second].push_back(temp.second);
				}
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int start = 0, end = 0, weight = 0;
		cin >> start >> end >> weight;
		graph[start].push_back({ weight, end });
		graph[end].push_back({ weight, start });
	}
	dijkstra(1);
	Min = dist[n];
	dis += dist[k];
	dijkstra(k);
	dis += dist[n];
	if (Min == dis) {
		cout << "SAVE HIM";
	}
	else {
		cout << "GOOD BYE";
	}
	return 0;
}
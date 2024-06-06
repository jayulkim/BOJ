#include <bits/stdc++.h>
#define INF 1000000001
using namespace std;
int dist[1001];
vector<pair<int, int>>graph[1001];
int Start = 0, End = 0;
int listgraph[1001];
void dijkstra(int Start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	for (int i = 1; i <= 1000; i++) {
		dist[i] = INF;
	}
	dist[Start] = 0;
	pq.push({ 0, Start });
	while (!pq.empty()) {
		pair<int, int>temp = pq.top();
		pq.pop();
		if (dist[temp.second] >= temp.first) {
			for (auto i : graph[temp.second]) {
				if (dist[i.second] > dist[temp.second] + i.first) {
					dist[i.second] = dist[temp.second] + i.first;
					pq.push({ dist[i.second], i.second });
					listgraph[i.second] = temp.second;
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
	}
	cin >> Start >> End;
	dijkstra(Start);
	cout << dist[End] << '\n';
	vector<int>result;
	result.push_back(End);
	while (End != Start) {
		result.push_back(listgraph[End]);
		End = listgraph[End];
	}
	cout << result.size() << '\n';
	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i] << ' ';
	}
	return 0;
}
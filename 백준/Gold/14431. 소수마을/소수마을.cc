#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
typedef long long ll;
vector<pair<int, int>>graph[4001];
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
bool ary[10001];
int dist[4001];
int n = 0;
int getdistence(int x1, int y1, int x2, int y2) {
	return (int)(sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}
void dijkstra(int start) {
	for (int i = 0; i <= n + 1; i++) {
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
	ary[0] = true;
	ary[1] = true;
	for (int i = 2; i * i <= 10000; i++) {
		if (!ary[i]) {
			for (int j = i * i; j <= 10000; j += i) {
				ary[j] = true;
			}
		}
	}
	int startx = 0, starty = 0, endx = 0, endy = 0;
	cin >> startx >> starty >> endx >> endy;
	cin >> n;
	vector<pair<int, int>>v(n + 2);
	v[0].first = startx;
	v[0].second = starty;
	for (int i = 1; i <= n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	v[n + 1].first = endx;
	v[n + 1].second = endy;
	for (int i = 0; i <= n; i++) {
		for (int j = i + 1; j <= n + 1; j++) {
			int dis = getdistence(v[i].first, v[i].second, v[j].first, v[j].second);
			if (!ary[dis]) {
				graph[i].push_back({ dis, j });
				graph[j].push_back({ dis, i });
			}
		}
	}
	dijkstra(0);
	if (dist[n + 1] == INF) {
		cout << -1;
	}
	else {
		cout << dist[n + 1];
	}
	return 0;
}
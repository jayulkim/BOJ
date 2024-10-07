#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;
struct pos {
	int y;
	int x;
	ll weight;
};
struct cmp {
	bool operator()(const pos& a, const pos& b) {
		return a.weight > b.weight;
	}
};
priority_queue<pos, vector<pos>, cmp>pq;
char Map[101][101];
int Forward[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
ll dist[101][101];
int m = 0, n = 0;
void dijkstra(int y, int x) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j] = INF;
		}
	}
	dist[y][x] = (ll)(Map[y][x] - 48);
	pq.push({ y, x, (ll)(Map[y][x] - 48) });
	while (!pq.empty()) {
		pos temp = pq.top();
		pq.pop();
		if (dist[temp.y][temp.x] >= temp.weight) {
			for (int i = 0; i < 4; i++) {
				int dy = temp.y + Forward[i][0];
				int dx = temp.x + Forward[i][1];
				if (dy >= 0 && dy < n && dx >= 0 && dx < m) {
					if (dist[dy][dx] > dist[temp.y][temp.x] + (ll)(Map[dy][dx] - 48)) {
						dist[dy][dx] = dist[temp.y][temp.x] + (ll)(Map[dy][dx] - 48);
						pq.push({ dy, dx, dist[dy][dx] });
					}
				}
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
		}
	}
	dijkstra(0, 0);
	cout << dist[n - 1][m - 1];
	return 0;
};
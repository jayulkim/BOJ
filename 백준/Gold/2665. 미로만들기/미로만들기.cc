#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
typedef long long ll;
char Map[51][51];
ll dist[51][51];
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
int n = 0;
int Forward[4][2] = { {-1, 0},{0, -1}, {1, 0}, {0, 1} };
void dijkstra(int y, int x) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
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
				if (dy >= 0 && dy < n && dx >= 0 && dx < n) {
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
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == '0') {
				Map[i][j] = '1';
			}
			else if (Map[i][j] == '1') {
				Map[i][j] = '0';
			}
		}
	}
	dijkstra(0, 0);
	cout << dist[n - 1][n - 1];
	return 0;
}
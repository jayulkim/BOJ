#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Forward[8][2] = { {-1, 1}, {0, 1}, {1, 1}, {-1, -1}, {1, 0}, {-1, 0}, {0, -1}, {1, -1} };
struct info {
	ll y;
	ll x;
	ll count;
	bool operator()(const info& a, const info& b) {
		return a.count > b.count;
	}
};
priority_queue<info, vector<info>, info>pq;
ll n = 0, m = 0;
ll sy = 0, sx = 0;
ll ey = 0, ex = 0;
char Map[501][501];
ll dist[501][501];
void dijkstra(ll y, ll x) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j] = LLONG_MAX;
		}
	}
	dist[y][x] = 0;
	pq.push({ y, x, 0 });
	while (!pq.empty()) {
		info temp = pq.top();
		pq.pop();
		if (dist[temp.y][temp.x] >= temp.count) {
			for (int i = 0; i < 3; i++) {
				ll dy = temp.y + Forward[i][0];
				ll dx = temp.x + Forward[i][1];
				if (dy >= 0 && dy < n && dx >= 0 && dx < m && Map[dy][dx] != '#') {
					if (dist[dy][dx] > dist[temp.y][temp.x]) {
						dist[dy][dx] = dist[temp.y][temp.x];
						pq.push({ dy, dx, dist[dy][dx] });
					}
				}
			}
			for (int i = 3; i < 8; i++) {
				ll dy = temp.y + Forward[i][0];
				ll dx = temp.x + Forward[i][1];
				if (dy >= 0 && dy < n && dx >= 0 && dx < m && Map[dy][dx] != '#') {
					if (dist[dy][dx] > dist[temp.y][temp.x] + 1) {
						dist[dy][dx] = dist[temp.y][temp.x] + 1;
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
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 'K') {
				sy = i;
				sx = j;
			}
			if (Map[i][j] == '*') {
				ey = i;
				ex = j;
			}
		}
	} 
	dijkstra(sy, sx);
	if (dist[ey][ex] == LLONG_MAX) {
		cout << -1;
	}
	else {
		cout << dist[ey][ex];
	}
	return 0;
}
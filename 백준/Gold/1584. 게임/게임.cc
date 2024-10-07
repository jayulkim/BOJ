#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Map[501][501];
ll Forward[4][2] = { {0, -1}, {-1, 0}, {1, 0}, {0, 1} };
ll dist[501][501];
ll n = 0, m = 0;
struct info {
	ll y;
	ll x;
	ll count;
	bool operator()(const info& a, const info& b) {
		return a.count > b.count;
	}
};
void dijkstra(ll y, ll x) {
	for (int i = 0; i <= 500; i++) {
		for (int j = 0; j <= 500; j++) {
			dist[i][j] = LLONG_MAX;
		}
	}
	dist[y][x] = 0;
	priority_queue<info, vector<info>, info>pq;
	pq.push({ y, x, 0 });
	while (!pq.empty()) {
		info temp = pq.top();
		pq.pop();
		if (dist[temp.y][temp.x] >= temp.count) {
			for (int i = 0; i < 4; i++) {
				ll dy = temp.y + Forward[i][0];
				ll dx = temp.x + Forward[i][1];
				if (dy >= 0 && dy <= 500 && dx >= 0 && dx <= 500 && Map[dy][dx] != 2) {
					if (Map[dy][dx] == 1) {
						if (dist[dy][dx] > dist[temp.y][temp.x] + 1) {
							dist[dy][dx] = dist[temp.y][temp.x] + 1;
							pq.push({ dy, dx, dist[dy][dx] });
						}
					}
					else if (!Map[dy][dx]) {
						if (dist[dy][dx] > dist[temp.y][temp.x]) {
							dist[dy][dx] = dist[temp.y][temp.x];
							pq.push({ dy, dx, dist[dy][dx] });
						}
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
		ll x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		for (ll j = min(y1, y2); j <= max(y1, y2); j++) {
			for (ll k = min(x1, x2); k <= max(x1, x2); k++) {
				Map[j][k] = max(Map[j][k], (ll)1);
			}
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		ll x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		for (ll j = min(y1, y2); j <= max(y1, y2); j++) {
			for (ll k = min(x1, x2); k <= max(x1, x2); k++) {
				Map[j][k] = max(Map[j][k], (ll)2);
			}
		}
	}
	dijkstra(0, 0);
	if (dist[500][500] == LLONG_MAX) {
		cout << -1;
	}
	else {
		cout << dist[500][500];
	}
	return 0;
}
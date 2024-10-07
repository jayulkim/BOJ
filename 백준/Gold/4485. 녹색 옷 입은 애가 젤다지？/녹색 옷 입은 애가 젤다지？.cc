#include <bits/stdc++.h>
#define INF 200000005
typedef long long ll;
using namespace std;
struct pos {
	int y;
	int x;
	ll weight;
};
struct cmp {
	bool operator() (const pos& a, const pos& b) {
		return a.weight > b.weight;
	}
};
priority_queue<pos, vector<pos>, cmp>pq;
int Forward[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
int n = 0;
ll dist[126][126];
ll Map[126][126];
void dijkstra(int y, int x) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = INF;
		}
	}
	dist[y][x] = Map[y][x];
	pq.push({ y, x, Map[y][x] });
	while (!pq.empty()) {
		pos temp = pq.top();
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int dy = temp.y + Forward[i][0];
			int dx = temp.x + Forward[i][1];
			if (dist[temp.y][temp.x] >= temp.weight)
			{
				if (dy >= 0 && dy < n && dx >= 0 && dx < n) {
					if (dist[dy][dx] > dist[temp.y][temp.x] + Map[dy][dx]) {
						dist[dy][dx] = dist[temp.y][temp.x] + Map[dy][dx];
						pq.push({ dy, dx, dist[dy][dx] });
					}
				}
			}
		}
	}
}
int main(void) {
	int num = 1;
	while (1) {
		cin >> n;
		if (n == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> Map[i][j];
			}
		}
		dijkstra(0, 0);
		cout << "Problem " << num << ": " << dist[n - 1][n - 1] << '\n';
		num++;
	}
	return 0;
}
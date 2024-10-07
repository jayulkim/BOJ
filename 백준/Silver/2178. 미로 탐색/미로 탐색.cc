#include <bits/stdc++.h>
using namespace std;
char Map[101][101];
int Forward[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
bool visited[101][101];
struct info {
	int y;
	int x;
	int dis;
};
void bfs(int y, int x, int n, int m) {
	queue<info>q;
	visited[y][x] = true;
	q.push({ y, x, 1 });
	while (!q.empty()) {
		info temp = q.front();
		q.pop();
		if (temp.y == n - 1 && temp.x == m - 1) {
			cout << temp.dis;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int dy = temp.y + Forward[i][0];
			int dx = temp.x + Forward[i][1];
			if (dy >= 0 && dy < n && dx >= 0 && dx < m && Map[dy][dx] == '1' && !visited[dy][dx]) {
				q.push({ dy, dx, temp.dis + 1 });
				visited[dy][dx] = true;
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
		}
	}
	bfs(0, 0, n, m);
	return 0;
}
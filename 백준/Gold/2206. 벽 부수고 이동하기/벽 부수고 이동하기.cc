#include <bits/stdc++.h>
using namespace std;
char Map[1001][1001];
bool visited[1001][1001];
bool wallvisited[1001][1001];
int Forward[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
struct info {
	int y;
	int x;
	int count = 0;
	bool wall;
};
int n = 0, m = 0;
void bfs(int y, int x) {
	visited[y][x] = true;
	queue<info>q;
	q.push({ y, x, 1, false });
	while (!q.empty()) {
		info temp = q.front();
		q.pop();
		if (temp.y == n - 1 && temp.x == m - 1) {
			cout << temp.count;
			return;
		}
		if (!temp.wall) {
			visited[temp.y][temp.x] = true;
		}
		else {
			wallvisited[temp.y][temp.x] = true;
		}
		for (int i = 0; i < 4; i++) {
			int dy = temp.y + Forward[i][0];
			int dx = temp.x + Forward[i][1];
			if (dy >= 0 && dy < n && dx >= 0 && dx < m) {
				if (Map[dy][dx] == '1' && !temp.wall && !wallvisited[dy][dx]) {
					q.push({ dy, dx, temp.count + 1, true });
					wallvisited[dy][dx] = true;
				}
				else if (Map[dy][dx] == '0' && !visited[dy][dx]) {
					if (!temp.wall) {
						q.push({ dy, dx, temp.count + 1, false });
						visited[dy][dx] = true;
					}
					else if (temp.wall && !wallvisited[dy][dx]) {
						q.push({ dy, dx, temp.count + 1, true });
						wallvisited[dy][dx] = true;
					}
				}
			}
		}
	}
	cout << -1;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
		}
	}
	bfs(0, 0);
	return 0;
}
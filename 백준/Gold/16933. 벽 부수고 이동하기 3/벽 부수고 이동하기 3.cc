#include <bits/stdc++.h>
using namespace std;
char Map[1001][1001];
bool visited[1001][1001];
bool wallvisited[1001][1001][11];
int Forward[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
struct info {
	int y;
	int x;
	int count;
	int wallcount;
	bool sun;
};
int n = 0, m = 0, k = 0;
void bfs(int y, int x) {
	visited[y][x] = true;
	queue<info>q;
	q.push({ y, x, 1, 0, true });
	while (!q.empty()) {
		info temp = q.front();
		q.pop();
		if (temp.y == n - 1 && temp.x == m - 1) {
			cout << temp.count;
			return;
		}
		if (temp.wallcount == 0) {
			visited[temp.y][temp.x] = true;
		}
		else if (temp.wallcount <= k) {
			wallvisited[temp.y][temp.x][temp.wallcount] = true;
		}
		for (int i = 0; i < 4; i++) {
			int dy = temp.y + Forward[i][0];
			int dx = temp.x + Forward[i][1];
			if (dy >= 0 && dy < n && dx >= 0 && dx < m) {
				if (Map[dy][dx] == '1' && temp.wallcount < k && !wallvisited[dy][dx][temp.wallcount]) {
					if (!temp.sun) {
						q.push({ temp.y, temp.x, temp.count + 1, temp.wallcount, !temp.sun });
					}
					else {
						q.push({ dy, dx, temp.count + 1, temp.wallcount + 1, !temp.sun });
						wallvisited[dy][dx][temp.wallcount] = true;
					}
				}
				else if (Map[dy][dx] == '0' && !visited[dy][dx]) {
					if (temp.wallcount == 0) {
						q.push({ dy, dx, temp.count + 1, 0,!temp.sun });
						visited[dy][dx] = true;
					}
					else if (temp.wallcount <= k && !wallvisited[dy][dx][temp.wallcount]) {
						q.push({ dy, dx, temp.count + 1, temp.wallcount, !temp.sun });
						wallvisited[dy][dx][temp.wallcount] = true;
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
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
		}
	}
	bfs(0, 0);
	return 0;
}
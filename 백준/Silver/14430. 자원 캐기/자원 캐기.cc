#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int Map[301][301];
int Forward[2][2] = { {1, 0}, {0, 1} };
int visited[301][301];
int n = 0, m = 0;
struct info {
	int y;
	int x;
	int sum;
};
void bfs(int y, int x) {
	queue<info>q;
	if (Map[y][x] == 1) {
		visited[y][x] = 1;
	}
	else {
		visited[y][x] = 0;
	}
	q.push({ y, x, visited[y][x] });
	while (!q.empty()) {
		info temp = q.front();
		q.pop();
		visited[temp.y][temp.x] = max(visited[temp.y][temp.x], temp.sum);
		for (int i = 0; i < 2; i++) {
			int dy = temp.y + Forward[i][0];
			int dx = temp.x + Forward[i][1];
			if (dy >= 0 && dy < n && dx >= 0 && dx < m) {
				if (Map[dy][dx] == 1 && visited[dy][dx] < temp.sum) {
					visited[dy][dx] = temp.sum;
					q.push({ dy, dx, temp.sum + 1 });
				}
				if (Map[dy][dx] == 0 && visited[dy][dx] < temp.sum) {
					visited[dy][dx] = temp.sum;
					q.push({ dy, dx, temp.sum });
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
			visited[i][j] = -1;
		}
	}
	bfs(0, 0);
	cout << visited[n - 1][m - 1];
	return 0;
}
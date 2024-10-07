#include <bits/stdc++.h>
using namespace std;
int Forward[8][2] = { {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {2, -1}, {2, 1}, {1, -2}, {1, 2} };
bool visited[301][301];
struct info {
	int y;
	int x;
	int dis;
};
void bfs(int starty, int startx, int endy, int endx, int n) {
	queue<info>q;
	visited[starty][startx] = true;
	q.push({ starty, startx, 0 });
	while (!q.empty()) {
		info temp = q.front();
		q.pop();
		if (temp.y == endy && temp.x == endx) {
			cout << temp.dis << '\n';
			return;
		}
		for (int i = 0; i < 8; i++) {
			int dy = temp.y + Forward[i][0];
			int dx = temp.x + Forward[i][1];
			if (dy >= 0 && dy < n && dx >= 0 && dx < n && !visited[dy][dx]) {
				q.push({ dy, dx, temp.dis + 1 });
				visited[dy][dx] = true;
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	while (num--) {
		int n = 0;
		cin >> n;
		int starty = 0, startx = 0, endy = 0, endx = 0;
		cin >> starty >> startx;
		cin >> endy >> endx;
		bfs(starty, startx, endy, endx, n);
		memset(visited, false, sizeof(visited));
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool visited[501][501];
int Forward[8][2] = { {-2, -1}, {-1, -2}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {2, 1}, {1, 2} };
int n = 0, m = 0;
int e[501][501];
int ary[1001];
void bfs(int y, int x) {
	visited[y][x] = true;
	queue<pair<pair<int, int>, int>>q;
	q.push({ { y, x }, 0 });
	while (!q.empty()) {
		pair<pair<int, int>, int> temp = q.front();
		q.pop();
		if (e[temp.first.first][temp.first.second]) {
			ary[e[temp.first.first][temp.first.second]] = temp.second;
		}
		visited[temp.first.first][temp.first.second] = true;
		for (int i = 0; i < 8; i++) {
			int dy = temp.first.first + Forward[i][0];
			int dx = temp.first.second + Forward[i][1];
			if (dy >= 0 && dy < n && dx >= 0 && dx < n && !visited[dy][dx]) {
				visited[dy][dx] = true;
				q.push({ { dy, dx }, temp.second + 1 });
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int starty = 0, startx = 0;
	cin >> starty >> startx;
	for (int i = 0; i < m; i++) {
		int y = 0, x = 0;
		cin >> y >> x;
		e[y - 1][x - 1] = i + 1;
	}
	bfs(starty - 1, startx - 1);
	for (int i = 1; i <= m; i++) {
		cout << ary[i] << ' ';
	}
	return 0;
}
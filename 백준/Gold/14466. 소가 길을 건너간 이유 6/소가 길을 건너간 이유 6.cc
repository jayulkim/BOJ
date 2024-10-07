#include <bits/stdc++.h>
using namespace std;
bool road[101][101][4];
bool visited[101][101];
int n = 0, m = 0, k = 0;
int Forward[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
void bfs(int y, int x) {
	visited[y][x] = true;
	queue<pair<int, int>>q;
	q.push({ y, x });
	while (!q.empty()) {
		pair<int, int>temp = q.front();
		q.pop();
		visited[temp.first][temp.second] = true;
		for (int i = 0; i < 4; i++) {
			int dy = temp.first + Forward[i][0];
			int dx = temp.second + Forward[i][1];
			if (dy >= 0 && dy < n && dx >= 0 && dx < n && !visited[dy][dx] && !road[temp.first][temp.second][i]) {
				visited[dy][dx] = true;
				q.push({ dy, dx });
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int starty = 0, startx = 0, endy = 0, endx = 0;
		cin >> starty >> startx >> endy >> endx;
		for (int j = 0; j < 4; j++) {
			int dy = starty + Forward[j][0];
			int dx = startx + Forward[j][1];
			if (dy == endy && dx == endx) {
				road[starty - 1][startx - 1][j] = true;
				road[endy - 1][endx - 1][(j + 2) % 4] = true;
			}
		}
	}
	vector<pair<int, int>>ary(m);
	for (int i = 0; i < m; i++) {
		cin >> ary[i].first >> ary[i].second;
	}
	int count = 0;
	for (int i = 0; i < m - 1; i++) {
		bfs(ary[i].first - 1, ary[i].second - 1);
		for (int j = i + 1; j < m; j++) {
			if (!visited[ary[j].first - 1][ary[j].second - 1]) {
				count++;
			}
		}
		memset(visited, false, sizeof(visited));
	}
	cout << count;
	return 0;
}
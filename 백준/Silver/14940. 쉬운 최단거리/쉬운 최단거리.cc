#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int Map[1001][1001];
int dist[1001][1001];
bool visited[1001][1001];
int Forward[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
int n = 0, m = 0, starty = 0, startx = 0;
void bfs() {
	dist[starty][startx] = 0;
	visited[starty][startx] = true;
	queue<pair<pair<int, int>, int>>q;
	q.push({ { starty, startx }, 0 });
	while (!q.empty()) {
		pair<pair<int, int>, int>temp = q.front();
		q.pop();
		dist[temp.first.first][temp.first.second] = temp.second;
		visited[temp.first.first][temp.first.second] = true;
		for (int i = 0; i < 4; i++) {
			int dy = temp.first.first + Forward[i][0];
			int dx = temp.first.second + Forward[i][1];
			if (dy >= 0 && dy < n && dx >= 0 && dx < m && Map[dy][dx] == 1 && !visited[dy][dx]) {
				q.push({ {dy, dx}, temp.second + 1 });
				visited[dy][dx] = true;
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
			if (Map[i][j] == 2) {
				starty = i;
				startx = j;
			}
		}
	}
	bfs();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == 0 && Map[i][j] == 1) {
				cout << -1 << ' ';
			}
			else {
				cout << dist[i][j] << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}
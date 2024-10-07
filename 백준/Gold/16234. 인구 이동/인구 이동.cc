#include <bits/stdc++.h>
using namespace std;
int Map[51][51];
bool visited[51][51];
int Forward[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

vector<pair<int, int>>v;
int bfs(int y, int x, int n, int l, int r) {
	int sum = 0;
	int count = 0;
	visited[y][x] = true;
	v.push_back({ y, x });
	queue<pair<int, int>>q;
	q.push({ y, x });
	while (!q.empty()) {
		pair<int, int>temp = q.front();
		v.push_back({ temp.first, temp.second });
		q.pop();
		sum += Map[temp.first][temp.second];
		visited[temp.first][temp.second] = true;
		count++;
		for (int i = 0; i < 4; i++) {
			int dy = temp.first + Forward[i][0];
			int dx = temp.second + Forward[i][1];
			if (dy >= 0 && dy < n && dx >= 0 && dx < n && abs(Map[temp.first][temp.second] - Map[dy][dx]) <= r && abs(Map[temp.first][temp.second] - Map[dy][dx]) >= l && !visited[dy][dx]) {
				visited[dy][dx] = true;
				q.push({ dy, dx });
			}
		}
	}
	return sum / count;
}
void update(int b) {
	while (!v.empty()) {
		pair<int, int>temp = v.back();
		v.pop_back();
		Map[temp.first][temp.second] = b;
	}
}
int result = 0;
void solve(int n, int l, int r) {
	while (1) {
		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					for (int k = 0; k < 4; k++) {
						int dy = i + Forward[k][0];
						int dx = j + Forward[k][1];
						if (dy >= 0 && dy < n && dx >= 0 && dx < n && !visited[dy][dx] && abs(Map[i][j] - Map[dy][dx]) >= l && abs(Map[i][j] - Map[dy][dx]) <= r) {
							int b = bfs(i, j, n, l, r);
							update(b);
							count++;
							break;
						}
					}
				}
			}
		}
		if (count == 0) {
			break;
		}
		memset(visited, false, sizeof(visited));
		result++;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, l = 0, r = 0;
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < n; j++) {
			cin >> Map[i][j];
		}
	}
	solve(n, l, r);
	cout << result;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n = 0, m = 0;
char Map[21][21];
bool visited[21][21];
bool alpha[27];
int Forward[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
vector<pair<int, int>>v;
int Max = 1;
void dfs(int y, int x) {
	visited[y][x] = true;
	alpha[Map[y][x] - 'A'] = true;
	for (int i = 0; i < 4; i++) {
		int dy = y + Forward[i][0];
		int dx = x + Forward[i][1];
		if (dy >= 0 && dy < n && dx >= 0 && dx < m && !visited[dy][dx] && !alpha[Map[dy][dx] - 'A']) {
			v.push_back({ dy, dx });
			Max = max(Max, (int)v.size() + 1);
			dfs(dy, dx);
			visited[dy][dx] = false;
			alpha[Map[dy][dx] - 'A'] = false;
			v.pop_back();
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
		}
	}
	dfs(0, 0);
	cout << Max;
	return 0;
}
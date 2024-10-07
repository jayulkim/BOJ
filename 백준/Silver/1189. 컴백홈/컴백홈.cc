#include <bits/stdc++.h>
using namespace std;
char Map[6][6];
bool visited[6][6];
int Forward[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
vector<pair<int, int>>load;
int n = 0, m = 0, k = 0;
int result = 0;
void dfs(int starty, int startx) {
	visited[starty][startx] = true;
	if (starty == 0 && startx == m - 1 && load.size() == k) {
		result++;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int dy = starty + Forward[i][0];
		int dx = startx + Forward[i][1];
		if (dy >= 0 && dy < n && dx >= 0 && dx < m && Map[dy][dx] != 'T' && !visited[dy][dx]) {
			load.push_back({ dy, dx });
			dfs(dy, dx);
			visited[dy][dx] = false;
			load.pop_back();
		}
	}
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
	load.push_back({ n - 1, 0 });
	visited[n - 1][0] = true;
	dfs(n - 1, 0);
	cout << result;
	return 0;
}
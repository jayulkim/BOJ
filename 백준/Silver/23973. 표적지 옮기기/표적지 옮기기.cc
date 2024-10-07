#include <bits/stdc++.h>
using namespace std;
int n = 0, m = 0;
char Map[2501][2501];
int visited[11];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<pair<int, int>>v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == '1') {
				v.push_back({ i, j });
			}
		}
	}
	for (auto& k : v) {
		int y = k.first, x = k.second;
		int find = true;
		for (int i = max(0, y - 9); i <= min(n - 1, y + 9); i++) {
			for (int j = max(0, x - 9); j <= min(m - 1, x + 9); j++) {
				if (Map[i][j] == '1') {
					visited[10 - max(abs(y - i), abs(x - j))]++;
				}
			}
		}
		for (int i = 1; i <= 10; i++) {
			if (visited[i] != 1) {
				find = false;
				break;
			}
		}
		if (find) {
			cout << y << ' ' << x;
			return 0;
		}
		memset(visited, 0, sizeof(visited));
	}
	cout << -1;
	return 0;
}
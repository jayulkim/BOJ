#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
char Map[1001][1001];
struct sector {
	int num;
	int count;
};
sector result[1001][1001];
unordered_set<int>s;
int solve[1001][1001];
bool visited[1001][1001];
int Forward[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
void bfs(int y, int x, int n, int m, int num) {
	int count = 0;
	visited[y][x] = true;
	queue<pair<int, int>>q;
	vector<pair<int, int>>v;
	q.push({ y, x });
	while (!q.empty()) {
		pair<int, int>temp = q.front();
		q.pop();
		count++;
		v.push_back({ temp.first, temp.second });
		visited[temp.first][temp.second] = true;
		for (int i = 0; i < 4; i++) {
			int dy = temp.first + Forward[i][0];
			int dx = temp.second + Forward[i][1];
			if (dy >= 0 && dy < n && dx >= 0 && dx < m && Map[dy][dx] == '0' && !visited[dy][dx]) {
				q.push({ dy, dx });
				visited[dy][dx] = true;
			}
		}
	}
	while (!v.empty()) {
		pair<int, int>temp = v.back();
		result[temp.first][temp.second].count = count;
		result[temp.first][temp.second].num = num;
		v.pop_back();
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	int num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (Map[i][j] == '0' && !visited[i][j]) {
				bfs(i, j, n, m, num);
				num++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (Map[i][j] == '1') {
				int sum = 0;
				for (int k = 0; k < 4; k++) {
					int dy = i + Forward[k][0];
					int dx = j + Forward[k][1];
					if (dy >= 0 && dy < n && dx >= 0 && dx < m && result[dy][dx].count != 0 && s.find(result[dy][dx].num) == s.end()) {
						s.insert(result[dy][dx].num);
						sum += result[dy][dx].count;
					}
				}
				unordered_set<int>().swap(s);
				solve[i][j] = sum + 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << solve[i][j] % 10;
		}
		cout << '\n';
	}
	return 0;
}
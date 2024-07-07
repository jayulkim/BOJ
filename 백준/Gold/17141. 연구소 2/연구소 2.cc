#include <bits/stdc++.h>
using namespace std;
bool visited[250001];
bool visitedMap[55][55];
int Map[55][55];
int Forward[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
vector<pair<int, int>>virus;
int white = 0;
vector<pair<int, int>>graph;
queue<pair<pair<int, int>, int>>q;
int temp = -1;
int n = 0, m = 0;
int Min = 2500001;
void bfs() {
	int count = 0;
	int Max = 0;
	while (!q.empty()) {
		pair<pair<int, int>, int>temp = q.front();
		count++;
		Max = max(Max, temp.second);
		visitedMap[temp.first.first][temp.first.second] = true;
		q.pop();
		if (count == white) {
			Min = min(Min, Max);
			return;
		}
		for (int i = 0; i < 4; i++) {
			int dy = temp.first.first + Forward[i][0];
			int dx = temp.first.second + Forward[i][1];
			if (dy >= 0 && dy < n && dx >= 0 && dx < n && !visitedMap[dy][dx] && Map[dy][dx] != 1) {
				q.push({ { dy, dx }, temp.second + 1 });
				visitedMap[dy][dx] = true;
			}
		}
	}
}
void dfs() {
	if (graph.size() == m) {
		for (auto& i : graph) {
			q.push({ {i.first, i.second}, 0 });
			visitedMap[i.first][i.second] = true;
		}
		bfs();
		memset(visitedMap, false, sizeof(visitedMap));
		return;
	}
	for (int i = temp + 1; i < virus.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			graph.push_back({ virus[i].first, virus[i].second });
			temp = i;
			dfs();
			visited[i] = false;
			graph.pop_back();
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	bool find = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 0) {
				white++;
				find = true;
			}
			else if (Map[i][j] == 2) {
				white++;
				virus.push_back({ i, j });
				find = true;
			}
		}
	}
	if (!find) {
		cout << 0;
		return 0;
	}
	dfs();
	if (Min == 2500001) {
		cout << -1;
		return 0;
	}
	cout << Min;
	return 0;
}
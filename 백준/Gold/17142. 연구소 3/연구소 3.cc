#include <bits/stdc++.h>
using namespace std;
bool visited[2501];
int visitedMap[51][51];
int Map[51][51];
int Forward[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
vector<pair<int, int>>virus;
vector<pair<int, int>>graph;
queue<pair<int, int>>q;
int temp = -1;
int n = 0, m = 0;
int Min = 2501;
void bfs() {
	int Max = 0;
	while (!q.empty()) {
		pair<int, int>temp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dy = temp.first + Forward[i][0];
			int dx = temp.second + Forward[i][1];
			if (dy >= 0 && dy < n && dx >= 0 && dx < n && visitedMap[dy][dx] == -1 && Map[dy][dx] != 1) {
				q.push({ dy, dx });
				visitedMap[dy][dx] = visitedMap[temp.first][temp.second] + 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visitedMap[i][j] == -1 && Map[i][j] != 1) {
				return;
			}
			else if (Map[i][j] == 0) {
				Max = max(Max, visitedMap[i][j]);
			}
		}
	}
	Min = min(Min, Max);
}
void dfs() {
	if (graph.size() == m) {
		memset(visitedMap, -1, sizeof(visitedMap));
		for (auto& i : graph) {
			q.push({i.first, i.second});
			visitedMap[i.first][i.second] = 0;
		}
		bfs();
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
				find = true;
			}
			else if (Map[i][j] == 2) {
				virus.push_back({ i, j });
			}
		}
	}
	if (!find) {
		cout << 0;
		return 0;
	}
	dfs();
	if (Min == 2501) {
		cout << -1;
		return 0;
	}
	cout << Min;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0;
ll sy = 0, sx = 0;
ll Forward[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
char Map[1001][1001];
bool visited[1001][1001];
ll dist[1001][1001];
ll rest[1001][1001];
vector<pair<ll, ll>>List;
vector<ll>graph = { 1 };
bool backtrack[21];
void bfs(ll y, ll x) {
	visited[y][x] = true;
	queue<pair<pair<ll, ll>, ll>>q;
	q.push({ {y, x}, 0 });
	while (!q.empty()) {
		pair<pair<ll, ll>, ll>temp = q.front();
		q.pop();
		if (Map[temp.first.first][temp.first.second] != 'S' && rest[temp.first.first][temp.first.second] && !(temp.first.first == y && temp.first.second == x)) {
			dist[rest[y][x]][rest[temp.first.first][temp.first.second]] = temp.second;
			dist[rest[temp.first.first][temp.first.second]][rest[y][x]] = temp.second;
		}
		visited[temp.first.first][temp.first.second] = true;
		for (int i = 0; i < 4; i++) {
			ll dy = temp.first.first + Forward[i][0];
			ll dx = temp.first.second + Forward[i][1];
			if (dy >= 0 && dy < n && dx >= 0 && dx < m && !visited[dy][dx] && Map[dy][dx] != 'X') {
				visited[dy][dx] = true;
				q.push({ {dy, dx}, temp.second + 1 });
			}
		}
	}
}
bool Find = false;
ll Min = LLONG_MAX;
void dfs() {
	if (graph.size() == 6) {
		if (graph[0] != 1) {
			return;
		}
		ll sum = 0, count = 0;
		for (int i = 0; i < graph.size() - 1; i++) {
			if (dist[graph[i]][graph[i + 1]]) {
				count++;
			}
			sum += dist[graph[i]][graph[i + 1]];
		}
		if (count < 5) {
			return;
		}
		Find = true;
		Min = min(Min, sum);
		return;
	}
	for (int i = 2; i <= List.size() + 1; i++) {
		if (!backtrack[i]) {
			graph.push_back(i);
			backtrack[i] = true;
			dfs();
			backtrack[i] = false;
			graph.pop_back();
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
			if (Map[i][j] == 'K') {
				List.push_back({ i, j });
				rest[i][j] = List.size() + 1;
			}
			else if (Map[i][j] == 'S') {
				sy = i;
				sx = j;
			}
		}
	}
	rest[sy][sx] = 1;
	bfs(sy, sx);
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < List.size(); i++) {
		bfs(List[i].first, List[i].second);
		memset(visited, false, sizeof(visited));
	}
	dfs();
	if (!Find) {
		cout << -1;
	}
	else {
		cout << Min;
	}
	return 0;
}
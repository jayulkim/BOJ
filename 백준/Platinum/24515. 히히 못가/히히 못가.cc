#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll> lll;
typedef tuple<pll, string, ll> pllsl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<vector<char>>Map(n + 5, vector<char>(n + 5));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> Map[i][j];
		}
	}
	Map[0][0] = '.';
	Map[0][1] = '.';
	Map[1][0] = '.';
	Map[n][n + 1] = '.';
	Map[n + 1][n] = '.';
	Map[n + 1][n + 1] = '.';
	for (int i = 2; i <= n + 1; i++) {
		Map[0][i] = '0';
	}
	for (int i = 1; i <= n - 1; i++) {
		Map[i][n + 1] = '0';
	}
	for (int i = 2; i <= n + 1; i++) {
		Map[i][0] = '0';
	}
	for (int i = 1; i <= n - 1; i++) {
		Map[n + 1][i] = '0';
	}
	ll Mapid = 0;
	vector<vector<ll>>idMap(n + 5, vector<ll>(n + 5, 0));
	vector<vector<bool>>visited(n + 5, vector<bool>(n + 5, false));
	queue<pll>q;
	vector<ll>weight(n * n + 5, 0);
	vector<pll>Forward1 = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
	function<void(ll, ll)> bfs = [&](ll y, ll x) -> void {
		visited[y][x] = true;
		q.push({ y, x });
		Mapid++;
		while (!q.empty()) {
			pll temp = q.front();
			q.pop();
			weight[Mapid]++;
			idMap[temp.first][temp.second] = Mapid;
			visited[temp.first][temp.second] = true;
			for (int i = 0; i < 4; i++) {
				ll dy = temp.first + Forward1[i].first;
				ll dx = temp.second + Forward1[i].second;
				if (dy >= 0 && dy <= n + 1 && dx >= 0 && dx <= n + 1 && !visited[dy][dx] && Map[dy][dx] == Map[y][x]) {
					visited[dy][dx] = true;
					q.push({ dy, dx });
				}
			}
		}
		};
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= n + 1; j++) {
			if (!visited[i][j] && Map[i][j] != '.') {
				bfs(i, j);
			}
		}
	}
	vector<pll>Forward2 = { {-1, 0}, {0, -1}, {1, 0}, {0, 1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
	vector<vector<pll>>graph(Mapid + 1);
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= n + 1; j++) {
			for (int k = 0; k < 8; k++) {
				ll dy = i + Forward2[k].first;
				ll dx = j + Forward2[k].second;
				if (dy >= 0 && dy <= n + 1 && dx >= 0 && dx <= n + 1 && idMap[dy][dx] != idMap[i][j] && Map[i][j] != '.' && Map[dy][dx] != '.') {
					if (idMap[i][j] == idMap[2][0] || idMap[i][j] == idMap[0][2]) {
						graph[idMap[dy][dx]].push_back({ 0, idMap[i][j] });
					}
					else {
						graph[idMap[dy][dx]].push_back({ weight[idMap[i][j]], idMap[i][j] });
					}
					if (idMap[dy][dx] == idMap[2][0] || idMap[dy][dx] == idMap[0][2]) {
						graph[idMap[i][j]].push_back({ 0, idMap[dy][dx] });
					}
					else {
						graph[idMap[i][j]].push_back({ weight[idMap[dy][dx]], idMap[dy][dx] });
					}
				}
			}		
		}
	}
	vector<ll>dist(Mapid + 1, LLONG_MAX);
	priority_queue<pll, vector<pll>, greater<pll>>pq;
	pq.push({ 0, idMap[0][2] });
	dist[idMap[0][2]] = 0;
	while (!pq.empty()) {
		pll temp = pq.top();
		pq.pop();
		if (dist[temp.second] >= temp.first) {
			for (auto& i : graph[temp.second]) {
				if (dist[i.second] > dist[temp.second] + i.first) {
					dist[i.second] = dist[temp.second] + i.first;
					pq.push({ dist[i.second], i.second });
				}
			}
		}
	}
	cout << dist[idMap[2][0]];
	return 0;
}
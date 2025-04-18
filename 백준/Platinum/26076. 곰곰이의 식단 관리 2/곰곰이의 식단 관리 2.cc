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
	cin >> n >> m;
	vector<vector<ll>>Map(n + 5, vector<ll>(m + 5));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> Map[i][j];
		}
	}
	Map[1][1] = 4;
	Map[n][m] = 4;
	Map[0][0] = 4;
	Map[0][1] = 4;
	Map[1][0] = 4;
	Map[n + 1][m + 1] = 4;
	Map[n + 1][m] = 4;
	Map[n][m + 1] = 4;
	for (int i = 2; i <= m + 1; i++) {
		Map[0][i] = 2;
	}
	for (int i = 1; i <= n - 1; i++) {
		Map[i][m + 1] = 2;
	}
	for (int i = 2; i <= n + 1; i++) {
		Map[i][0] = 3;
	}
	for (int i = 1; i <= m - 1; i++) {
		Map[n + 1][i] = 3;
	}
	ll Mapid = 0;
	vector<vector<ll>>idMap(n + 5, vector<ll>(m + 5, 0));
	vector<vector<ll>>v(n + 5, vector<ll>(m + 5, 1));
	vector<vector<bool>>visited(n + 5, vector<bool>(m + 5, false));
	vector<vector<bool>>vv(n + 5, vector<bool>(m + 5, false));
	vector<pll>Forward1 = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
	vector<pll>Forward2 = { {-1, 0}, {0, -1}, {1, 0}, {0, 1}, {-1, -1}, {1, -1}, {1, 1}, {-1, 1} };
	function<void(ll, ll)> bfs = [&](ll y, ll x) -> void {
		visited[y][x] = true;
		queue<pll>q;
		q.push({ y, x });
		Mapid++;
		while (!q.empty()) {
			pll temp = q.front();
			q.pop();
			v[temp.first][temp.second] = 0;
			visited[temp.first][temp.second] = true;
			idMap[temp.first][temp.second] = Mapid;
			for (int i = 0; i < 4; i++) {
				ll dy = temp.first + Forward1[i].first;
				ll dx = temp.second + Forward1[i].second;
				if (dy >= 0 && dy <= n + 1 && dx >= 0 && dx <= m + 1 && Map[dy][dx] == Map[y][x] && !visited[dy][dx]) {
					visited[dy][dx] = true;
					q.push({ dy, dx });
				}
			}               
		}
		};
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			if (!Map[i][j]) {
				Mapid++;
				idMap[i][j] = Mapid;
			}
			else if (!visited[i][j]) {
				bfs(i, j);
			}
		}
	}
	vector<vector<pll>>graph(Mapid + 1);
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			for (int k = 0; k < 8; k++) {
				ll dy = i + Forward2[k].first;
				ll dx = j + Forward2[k].second;
				if (dy >= 0 && dy <= n + 1 && dx >= 0 && dx <= m + 1 && idMap[i][j] != idMap[dy][dx] && Map[i][j] != 4 && Map[dy][dx] != 4) {
					graph[idMap[i][j]].push_back({ v[dy][dx], idMap[dy][dx] });
				}
			}
		}
	}
	priority_queue<pll, vector<pll>, greater<pll>>pq;
	pq.push({ 0, idMap[0][2] });
	vector<ll>dist(Mapid + 1, LLONG_MAX);
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
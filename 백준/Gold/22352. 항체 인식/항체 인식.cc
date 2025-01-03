#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll Map[31][31];
bool visited[31][31];
ll Forward[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
vector<map<pll, ll>>graph;
ll compareMap[31][31];
void bfs(ll y, ll x, ll num) {
	visited[y][x] = true;
	queue<pll>q;
	map<pll, ll>M;
	q.push({ y, x });
	while (!q.empty()) {
		pll temp = q.front();
		q.pop();
		M[{temp.first, temp.second}]++;
		visited[temp.first][temp.second] = true;
		for (int i = 0; i < 4; i++) {
			ll dy = temp.first + Forward[i][0];
			ll dx = temp.second + Forward[i][1];
			if (dy >= 0 && dy < n && dx >= 0 && dx < m && !visited[dy][dx] && Map[dy][dx] == num) {
				visited[dy][dx] = true;
				q.push({ dy, dx });
			}
		}
	}
	graph.push_back(M);
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
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> compareMap[i][j];     
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				bfs(i, j, Map[i][j]);
			}
		}
	}
	ll count = 0;
	for (int i = 0; i < graph.size(); i++) {
		auto it = graph[i].begin();
		ll num = compareMap[it->first.first][it->first.second];
		ll temp = 0;
		for (auto& j : graph[i]) {
			if (num != Map[j.first.first][j.first.second]) {
				temp++;
			}
			if (compareMap[j.first.first][j.first.second] != num) {
				cout << "NO";
				return 0;
			}
		}
		if (temp && temp != graph[i].size()) {
			cout << "NO";
			return 0;
		}
		else if (temp) {
			count++;
		}
	}
	if (count > 1) {
		cout << "NO";
		return 0;
	}
	cout << "YES";
	return 0;
}
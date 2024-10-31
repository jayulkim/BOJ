#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll Map[501][501];
bool visited[501][501];
ll Forward[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
void bfs(ll y, ll x) {
	queue<pll>q;
	visited[y][x] = true;
	q.push({ y, x });
	while (!q.empty()) {
		pll temp = q.front();
		q.pop();
		visited[temp.first][temp.second] = true;
		for (int i = 0; i < 4; i++) {
			ll dy = temp.first + Forward[i][0];
			ll dx = temp.second + Forward[i][1];
			if (dy >= 0 && dy < n && dx >= 0 && dx < m && llabs(Map[temp.first][temp.second] - Map[dy][dx]) <= k && !visited[dy][dx]) {
				visited[dy][dx] = true;
				q.push({ dy, dx });
			}
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
	ll count = 0;
	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				count++;
				bfs(i, j);
			}
		}
	}
	cout << count;
	return 0;
}
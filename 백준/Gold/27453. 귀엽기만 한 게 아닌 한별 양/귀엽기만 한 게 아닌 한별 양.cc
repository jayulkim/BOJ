#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<string, ll> psl;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll, ll, ll, ll, ll, ll>llllllll;
ll n = 0, m = 0, k = 0;
char Map[1001][1001];
bool visited[1001][1001][4];
ll Forward[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
void bfs(ll y, ll x) {
	queue<llllllll>q;
	for (int i = 0; i < 4; i++) {
		visited[y][x][0] = true;
		ll dy = y + Forward[i][0];
		ll dx = x + Forward[i][1];
		if (dy >= 0 && dy < n && dx >= 0 && dx < m && Map[dy][dx] != 'X') {
			q.push({ dy, dx, i, 0, Map[dy][dx] - '0', 1, y, x });
		}
	}
	while (!q.empty()) {
		auto [a, b, c, d, e, f, g, h] = q.front();
		q.pop();
		visited[a][b][c] = true;
		if (Map[a][b] == 'H') {
			cout << f;
			exit(0);
		}
		for (int j = 0; j < 4; j++) {
			ll dy = a + Forward[j][0];
			ll dx = b + Forward[j][1];
			if (dy >= 0 && dy < n && dx >= 0 && dx < m && !(dy == g && dx == h) && !visited[dy][dx][j] && Map[dy][dx] != 'X' && ((Map[dy][dx] != 'H' && d + e + Map[dy][dx] - '0' <= k) || Map[dy][dx] == 'H')) {
				visited[dy][dx][j] = true;
				q.push({ dy, dx, j, e, Map[dy][dx] - '0', f + 1, a, b });
			}
		}
	}
	cout << -1;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	ll y = 0, x = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 'S') {
				y = i;
				x = j;
			}
		}
	}
	bfs(y, x);
	return 0;
}
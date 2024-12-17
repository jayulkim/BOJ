#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
bool visited[101][101];
char Map[101][101];
ll Forward[8][2] = { {-1, -1}, {-1, 0}, {0, -1}, {1, 1}, {1, 0}, {0, 1}, {1, -1}, {-1, 1} };
void bfs(ll y, ll x) {
	visited[y][x] = true;
	queue<pll>q;
	q.push({ y, x });
	while (!q.empty()) {
		pll temp = q.front();
		q.pop();
		visited[temp.first][temp.second] = true;
		for (int i = 0; i < 8; i++) {
			ll dy = temp.first + Forward[i][0];
			ll dx = temp.second + Forward[i][1];
			if (dy >= 0 && dy < n && dx >= 0 && dx < m && !visited[dy][dx] && Map[dy][dx] == '@') {
				q.push({ dy, dx });
				visited[dy][dx] = true;
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		cin >> n >> m;
		if (!n && !m) {
			break;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> Map[i][j];
			}
		}
		ll count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && Map[i][j] == '@') {
					count++;
					bfs(i, j);
				}
			}
		}
		cout << count << '\n';
		memset(visited, false, sizeof(visited));
	}
	return 0;
}
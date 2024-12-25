#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
bool visited[101][101];
ll Forward[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
char Map[101][101];
void bfs(ll y, ll x) {
	visited[y][x] = true;
	queue<pll>q;
	q.push({ y, x });
	while (!q.empty()) {
		pll temp = q.front();
		q.pop();
		visited[temp.first][temp.second] = true;
		for (int i = 0; i < 4; i++) {
			ll dy = temp.first + Forward[i][0];
			ll dx = temp.second + Forward[i][1];
			if (dy >= 0 && dy < n && dx >= 0 && dx < m && !visited[dy][dx] && Map[dy][dx] == '1') {
				visited[dy][dx] = true;
				q.push({ dy, dx });
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	ll result = 0;
	while (num--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> Map[i][j];
			}
		}
		cin >> k;
		cout << "Case #" << ++result << ':' << '\n';
		for (int i = 0; i < k; i++) {
			char command;
			ll a = 0, b = 0, c = 0;
			cin >> command;
			if (command == 'Q') {
				ll count = 0;
				for (int j = 0; j < n; j++) {
					for (int u = 0; u < m; u++) {
						if (!visited[j][u] && Map[j][u] == '1') {
							count++;
							bfs(j, u);
						}
					}
				}
				cout << count << '\n';
				memset(visited, false, sizeof(visited));
			}
			else {
				cin >> a >> b >> c;
				Map[a][b] = c + '0';
			}
		}
	}
	return 0;
}
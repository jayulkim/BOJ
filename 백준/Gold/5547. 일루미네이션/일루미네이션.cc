#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll Map[105][105];
ll ary[105][105];
ll a[6][2] = { {-1, -1}, {-1, 0}, {0, 1}, {0, -1}, {1, 0}, {1, -1} };
ll b[6][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {0, -1} };
ll result = 0;
bool visited[105][105];
void bfs(ll y, ll x) {
	visited[y][x] = true;
	queue<pll>q;
	q.push({ y, x });
	while (!q.empty()) {
		pll temp = q.front();
		q.pop();
		visited[temp.first][temp.second] = true;
		if (temp.first % 2 == 0) {
			for (int i = 0; i < 6; i++) {
				ll dy = temp.first + a[i][0];
				ll dx = temp.second + a[i][1];
				if (dy >= 0 && dy <= n + 1 && dx >= 0 && dx <= m + 1) {
					if (!Map[dy][dx] && !visited[dy][dx]) {
						visited[dy][dx] = true;
						q.push({ dy, dx });
					}
					ary[dy][dx] += Map[dy][dx];
					result += Map[dy][dx];
				}
			}
		}
		else {
			for (int i = 0; i < 6; i++) {
				ll dy = temp.first + b[i][0];
				ll dx = temp.second + b[i][1];
				if (dy >= 0 && dy <= n + 1 && dx >= 0 && dx <= m + 1) {
					if (!Map[dy][dx] && !visited[dy][dx]) {
						visited[dy][dx] = true;
						q.push({ dy, dx });
					}
					ary[dy][dx] += Map[dy][dx];
					result += Map[dy][dx];
				}
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> Map[i][j];
		}
	}
	bfs(0, 0);
	cout << result;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0;
ll k = 0, c = 0;
ll starty = 0, startx = 0, endy = 0, endx = 0;
char Map[101][101];
int Forward[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
ll visited[101][101][101];
struct info {
	ll y;
	ll x;
	ll tem;
	ll count;
};
void bfs() {
	queue<info>q;
	q.push({ starty, startx, 0, 0 });
	while (!q.empty()) {
		info temp = q.front();
		q.pop();
 		if (temp.y == endy && temp.x == endx) {
			cout << temp.count;
			return;
		}
		visited[temp.y][temp.x][temp.tem] = temp.count;
		if (Map[temp.y][temp.x] == 'H' && temp.tem - k >= 0 && !visited[temp.y][temp.x][max((ll)0, temp.tem - k)]) {
			if (!visited[temp.y][temp.x][max((ll)0, temp.tem - k)]) {
				visited[temp.y][temp.x][max((ll)0, temp.tem - k)] = temp.count + 1;
				q.push({ temp.y, temp.x, max((ll)0, temp.tem - k), temp.count + 1 });
			}
		}
		for (int i = 0; i < 4; i++) {
			ll dy = temp.y + Forward[i][0];
			ll dx = temp.x + Forward[i][1];
			if (dy >= 0 && dy < n && dx >= 0 && dx < m && !visited[dy][dx][temp.tem] && Map[dy][dx] != '#' && !(temp.tem == 0 && dy == starty && dx == startx)) {
				if (!visited[dy][dx][temp.tem]) {
					if (Map[dy][dx] == 'H') {
						if (!visited[dy][dx][max(temp.tem - k, (ll)0)]) {
							visited[dy][dx][max(temp.tem - k, (ll)0)] = temp.count + 1;
							q.push({ dy, dx, max(temp.tem - k, (ll)0), temp.count + 1 });
						}
					}
					else {
						ll t = min((ll)100, temp.tem + c);
						if (t < 100 && !visited[dy][dx][t]) {
							visited[dy][dx][t] = temp.count + 1;
							q.push({ dy, dx, t, temp.count + 1 });
						}
					}
				}		
			}
		}
	}
	cout << -1;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	cin >> k >> c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 'S') {
				starty = i;
				startx = j;
			}
			if (Map[i][j] == 'E') {
				endy = i;
				endx = j;
			}
		}
	}
	bfs();
 	return 0;
}
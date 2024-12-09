#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double ld;
ll n = 0, m = 0, k = 0;
char Map[601][601];
ll Forward[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
bool visited[601][601];
ll bfs(ll y, ll x) {
	visited[y][x] = true;
	queue<pll>q;
	q.push({ y, x });
	ll count = 0;
	while (!q.empty()) {
		pll temp = q.front();
		q.pop();
		if (Map[temp.first][temp.second] == 'P') {
			count++;
		}
		visited[temp.first][temp.second] = true;
		for (int i = 0; i < 4; i++) {
			ll dy = temp.first + Forward[i][0];
			ll dx = temp.second + Forward[i][1];
			if (dy >= 0 && dy < n && dx >= 0 && dx < m && Map[dy][dx] != 'X' && !visited[dy][dx]) {
				visited[dy][dx] = true;
				q.push({ dy, dx });
			}
		}
	}
	return count;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	ll starty = 0, startx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 'I') {
				starty = i;
				startx = j;
			}
		}
	}
	ll temp = bfs(starty, startx);
	if (!temp) {
		cout << "TT";
	}
	else {
		cout << temp;
	}

	return 0;
}
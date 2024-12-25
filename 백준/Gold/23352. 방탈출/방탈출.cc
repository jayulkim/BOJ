#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll Map[51][51];
bool visited[51][51];
ll Forward[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
pll Max = { 0, 0 };
void bfs(ll starty, ll startx) {
	visited[starty][startx] = true;
	queue<tp>q;
	q.push({ starty, startx, 0 });
	while (!q.empty()) {
		tp temp = q.front();
		q.pop();
		auto [a, b, c] = temp;
		visited[a][b] = true;
		for (int i = 0; i < 4; i++) {
			ll dy = a + Forward[i][0];
			ll dx = b + Forward[i][1];
			if (dy >= 0 && dy < n && dx >= 0 && dx < m && !visited[dy][dx] && Map[dy][dx]) {
				Max = max(Max, { c + 1, Map[starty][startx] + Map[dy][dx] });
				visited[dy][dx] = true;
				q.push({ dy, dx, c + 1 });
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<pll>v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
			if (Map[i][j]) {
				v.push_back({ i, j });
			}
		}
	}
	if (!v.size()) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (Map[i][j]) {
				bfs(i, j);
				memset(visited, false, sizeof(visited));
			}
		}
	}
	cout << Max.second;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, char> plc;
typedef pair<string, ll> psl;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll, ll, ll, ll, ll, ll>llllllll;
ll n = 0, m = 0, k = 0;
char Map[51][51];
vector<vector<pll>>dp(51, vector<pll>(51, { LLONG_MAX, LLONG_MAX }));
ll Forward[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
void bfs(ll y, ll x) {
	queue<llll>q;
	q.push({ y, x, 0, 0 });
	dp[y][x] = { 0, 0 };
	while (!q.empty()) {
		auto [a, b, c, d] = q.front();
		q.pop();
		dp[a][b] = min(dp[a][b], { c, d });
		if (dp[a][b].first >= c || (dp[a][b].first == c && dp[a][b].second >= d)) {
			for (int i = 0; i < 4; i++) {
				ll dy = a + Forward[i][0];
				ll dx = b + Forward[i][1];
				if (dy >= 0 && dy < n && dx >= 0 && dx < m) {
					ll aa = 0, bb = 0;
					if (Map[dy][dx] == '.') {
						for (int j = 0; j < 4; j++) {
							ll dydy = dy + Forward[j][0];
							ll dxdx = dx + Forward[j][1];
							if (dydy >= 0 && dydy < n && dxdx >= 0 && dxdx < m && Map[dydy][dxdx] == 'g' && !(dydy == dy && dxdx == dx)) {
								aa = 1;
								break;
							}
						}
					}
					if (Map[dy][dx] == 'g') {
						bb = 1;
					}
					if (c + bb == dp[dy][dx].first) {
						if (d + aa < dp[dy][dx].second) {
							dp[dy][dx] = { c + bb, d + aa };
							q.push({ dy, dx, c + bb, d + aa });
						}
					}
					else if (c + bb < dp[dy][dx].first) {
						dp[dy][dx] = { c + bb, d + aa };
						q.push({ dy, dx, c + bb, d + aa });
					}
				}
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	ll starty = 0, startx = 0, endy = 0, endx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 'S') {
				starty = i;
				startx = j;
			}
			if (Map[i][j] == 'F') {
				endy = i;
				endx = j;
			}
		}
	}
	bfs(starty, startx);
	cout << dp[endy][endx].first << ' ' << dp[endy][endx].second;
	return 0;
}
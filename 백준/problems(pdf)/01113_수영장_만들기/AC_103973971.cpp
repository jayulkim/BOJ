#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<vector<char>>Map(n + 1, vector<char>(m + 1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
		}
	}
	vector<vector<ll>>forward = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
	vector<vector<ll>>vii(n + 1, vector<ll>(m + 1, 0));
	ll result = 0;
	for (int i = 9; i >= 2; i--) {
		vector<vector<ll>>vi(n + 1, vector<ll>(m + 1, 0));
		queue<pll>q;
		for (int j = 0; j < n; j++) {
			if (Map[j][0] - '0' < i) {
				q.push({ j, 0 });
			}
			if (Map[j][m - 1] - '0' < i) {
				q.push({ j, m - 1 });
			}
		}
		for (int j = 0; j < m; j++) {
			if (Map[0][j] - '0' < i) {
				q.push({ 0, j });
			}
			if (Map[n - 1][j] - '0' < i) {
				q.push({ n - 1, j });
			}
		}
		while (!q.empty()) {
			auto [a, b] = q.front();
			q.pop();
			vi[a][b] = 1;
			for (int j = 0; j < 4; j++) {
				ll dy = a + forward[j][0];
				ll dx = b + forward[j][1];
				if (dy >= 0 && dy < n && dx >= 0 && dx < m && !vi[dy][dx] && Map[dy][dx] - '0' < i) {
					vi[dy][dx] = 1;
					q.push({ dy, dx });
				}
			}
		}
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (!vii[j][k] && !vi[j][k]) {
					vii[j][k] = i;
					result += (i - Map[j][k] + '0');
				}
			}
		}
	}
	cout << result;
	return 0;
}
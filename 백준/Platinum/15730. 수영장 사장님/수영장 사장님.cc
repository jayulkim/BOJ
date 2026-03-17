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
	vector<vector<ll>>Map(n + 1, vector<ll>(m + 1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
		}
	}
	vector<vector<ll>>forward = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
	vector<vector<ll>>flood(n + 1, vector<ll>(m + 1, -1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (flood[i][j] == -1) {
				vector<vector<ll>>vi(n + 1, vector<ll>(m + 1, 0));
				bool find = false;
				vector<pll>v;
				queue<pll>q;
				q.push({ i, j });
				while (!q.empty()) {
					auto [a, b] = q.front();
					q.pop();
					vi[a][b] = 1;
					if (Map[a][b] == Map[i][j]) {
						v.push_back({ a, b });
					}
					for (int k = 0; k < 4; k++) {
						ll dy = a + forward[k][0];
						ll dx = b + forward[k][1];
						if (dy >= 0 && dy < n && dx >= 0 && dx < m) {
							if (!vi[dy][dx] && Map[dy][dx] <= Map[i][j]) {
								vi[dy][dx] = 1;
								q.push({ dy, dx });
							}
						}
						else {
							find = true;
						}
					}
				}
				for (auto& [a, b] : v) {
					flood[a][b] = find;
				}
			}
		}
	}
	vector<vector<ll>>vii(n + 1, vector<ll>(m + 1, 0));
	ll result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!flood[i][j] && !vii[i][j]) {
				queue<pll>q;
				vector<ll>v;
				ll Min = LLONG_MAX;
				q.push({ i, j });
				while (!q.empty()) {
					auto [a, b] = q.front();
					q.pop();
					vii[a][b] = 1;
					v.push_back(Map[a][b]);
					for (int k = 0; k < 4; k++) {
						ll dy = a + forward[k][0];
						ll dx = b + forward[k][1];
						if (flood[dy][dx]) {
							Min = min(Min, Map[dy][dx]);
						}
						if (!vii[dy][dx] && !flood[dy][dx]) {
							vii[dy][dx] = 1;
							q.push({ dy, dx });
						}
					}
				}
				for (auto& k : v) {
					result += (Min - k);
				}
			}
		}
	}
	cout << result;
	return 0;
}
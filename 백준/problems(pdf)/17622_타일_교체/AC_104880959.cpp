#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<vector<ll>>Map(n + 1, vector<ll>(n + 1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Map[i][j];
		}
	}
	vector<vector<ll>>forward = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
	function<ll(ll, ll, ll)> check = [&](ll a, ll b, ll c) -> ll {
		ll result = 0;
		ll y = a, x = b;
		while (1) {
			result++;
			ll dy = y + forward[c][0];
			ll dx = x + forward[c][1];
			if (dy >= 0 && dy < n && dx >= 0 && dx < n) {
				if (Map[dy][dx] == 0) {
					if (c == 2 || c == 1) {
						return LLONG_MAX;
					}
					if (c == 0) {
						c = (c + 1) % 4;
					}
					else {
						c = (c + 3) % 4;
					}
				}
				else if (Map[dy][dx] == 1) {
					if (c == 2 || c == 3) {
						return LLONG_MAX;
					}
					if (c == 0) {
						c = (c + 3) % 4;
					}
					else {
						c = (c + 1) % 4;
					}
				}
				else if (Map[dy][dx] == 2) {
					if (c == 0 || c == 1) {
						return LLONG_MAX;
					}
					if (c == 2) {
						c = (c + 3) % 4;
					}
					else {
						c = (c + 1) % 4;
					}
				}
				else if (Map[dy][dx] == 3) {
					if (c == 0 || c == 3) {
						return LLONG_MAX;
					}
					if (c == 1) {
						c = (c + 3) % 4;
					}
					else {
						c = (c + 1) % 4;
					}
				}
				else if (Map[dy][dx] == 4) {
					if (c == 1 || c == 3) {
						return LLONG_MAX;
					}
				}
				else {
					if (c == 0 || c == 2) {
						return LLONG_MAX;
					}
				}
				y = dy;
				x = dx;
			}
			else if (dy == n - 1 && dx == n) {
				return result - 1;
			}
			else {
				return LLONG_MAX;
			}
		}
		};
	ll result = LLONG_MAX;
	if (m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ll temp = Map[i][j];
				for (int k = 0; k < 6; k++) {
					if (temp != k) {
						Map[i][j] = k;
						result = min(result, check(0, -1, 1));
					}
				}
				Map[i][j] = temp;
			}
		}
	}
	else {
		result = check(0, -1, 1);
	}
	if (result == LLONG_MAX) {
		cout << -1;
	}
	else {
		cout << result;
	}
	return 0;
}
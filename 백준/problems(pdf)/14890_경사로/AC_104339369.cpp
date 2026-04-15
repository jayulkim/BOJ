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
	vector<vector<ll>>vi(n + 1, vector<ll>(n + 1, 0));
	vector<vector<ll>>forward = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
	function<ll(ll, ll, ll, ll)> check = [&](ll a, ll b, ll c, ll d) -> ll {
		ll result = 0;
		ll y = a;
		ll x = b;
		vector<pll>v;
		for (int i = 0; i < m; i++) {
			if (y >= 0 && y < n && x >= 0 && x < n && !vi[y][x] && Map[y][x] == d) {
				v.push_back({ y, x });
			}
			else {
				result = 1;
				break;
			}
			y += forward[c][0];
			x += forward[c][1];
		}
		for (auto& [a, b] : v) {
			vi[a][b] = 1;
		}
		return result;
		};
	ll count = 0;
	vector<ll>a(n + 1, 0);
	vector<ll>b(n + 1, 0);
	for (int i = 0; i < n; i++) {
		vector<vector<ll>>(n + 1, vector<ll>(n + 1, 0)).swap(vi);
		bool find = false;
		for (int j = 0; j < n - 1; j++) {
			ll h = Map[i][j + 1] - Map[i][j];
			if (h == 1 && !check(i, j, 1, Map[i][j])) {
				continue;
			}
			if (h == -1 && !check(i, j + 1, 2, Map[i][j + 1])) {
				continue;
			}
			if (!h) {
				continue;
			}
			find = true;
			break;
		}
		if (!find) {
			a[i] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		bool find = false;
		vector<vector<ll>>(n + 1, vector<ll>(n + 1, 0)).swap(vi);
		for (int j = 0; j < n - 1; j++) {
			ll h = Map[j + 1][i] - Map[j][i];
			if (h == 1 && !check(j, i, 0, Map[j][i])) {
				continue;
			}
			if (h == -1 && !check(j + 1, i, 3, Map[j + 1][i])) {
				continue;
			}
			if (!h) {
				continue;
			}
			find = true;
			break;
		}
		if (!find) {
			b[i] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		count += a[i];
		count += b[i];
	}
	cout << count;
	return 0;
}
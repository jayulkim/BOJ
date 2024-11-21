#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
struct info {
	ll s;
	ll d;
	ll z;
};
vector<vector<info>>Map(101, vector<info>(101, { 0, 0, 0 }));
ll result = 0;
ll Forward[5][2] = { {0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
void getmoolgogi(ll c) {
	for (int i = 1; i <= n; i++) {
		if (Map[i][c].d) {
			result += Map[i][c].z;
			Map[i][c] = { 0, 0, 0 };
			return;
		}
	}
}
void update() {
	vector<vector<info>>updateMap(101, vector<info>(101, { 0, 0, 0 }));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (Map[i][j].d) {
				info temp = Map[i][j];
				ll dy = i + Forward[temp.d][0] * temp.s;
				ll dx = j + Forward[temp.d][1] * temp.s;
				if (dy >= 1 && dy <= n && dx >= 1 && dx <= m) {
					if (updateMap[dy][dx].z <= temp.z) {
						if (temp.d == 1 && dy == 1) {
							temp.d = 2;
						}
						else if (temp.d == 2 && dy == n) {
							temp.d = 1;
						}
						else if (temp.d == 3 && dx == m) {
							temp.d = 4;
						}
						else if (temp.d == 4 && dx == 1) {
							temp.d = 3;
						}
						updateMap[dy][dx] = temp;
					}
				}
				else {
					if (temp.d == 1) {
						ll a = temp.s;
						a -= (i - 1);
						if ((a / (n - 1)) % 2) {
							a %= (n - 1);
							dy = n;
							dy -= a;
							if (dy == 1) {
								temp.d = 2;
							}
						}
						else {
							a %= (n - 1);
							dy = 1;
							dy += a;
							temp.d = 2;
						}
					}
					else if (temp.d == 2) {
						ll a = temp.s;
						a -= (n - i);
						if ((a / (n - 1)) % 2) {
							a %= (n - 1);
							dy = 1;
							dy += a;
							if (dy == n) {
								temp.d = 2;
							}
						}
						else {
							a %= (n - 1);
							dy = n;
							dy -= a;
							temp.d = 1;
						}
					}
					else if (temp.d == 3) {
						ll a = temp.s;
						a -= (m - j);
						if ((a / (m - 1)) % 2) {
							a %= (m - 1);
							dx = 1;
							dx += a;
							if (dx == m) {
								temp.d = 4;
							}
						}
						else {
							a %= (m - 1);
							dx = m;
							dx -= a;
							temp.d = 4;
						}
					}
					else if (temp.d == 4) {
						ll a = temp.s;
						a -= (j - 1);
						if ((a / (m - 1)) % 2) {
							a %= (m - 1);
							dx = m;
							dx -= a;
							if (dx == 1) {
								temp.d = 3;
							}
						}
						else {
							a %= (m - 1);
							dx = 1;
							dx += a;
							temp.d = 3;
						}
					}
					if (updateMap[dy][dx].z <= temp.z) {
						updateMap[dy][dx] = temp;
					}
				}
			}
		}
	}
	Map = updateMap;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		ll r = 0, c = 0, s = 0, d = 0, z = 0;
		cin >> r >> c >> s >> d >> z;
		Map[r][c] = { s, d, z };
	}
	for (int i = 1; i <= m; i++) {
		getmoolgogi(i);
		update();
	}
	cout << result;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
map<pll, ll>Map;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		ll x = 0, y = 0;
		cin >> x >> y;
		Map[{x, y}]++;
	}
	string command = "";
	cin >> command;
	ll x = 0, y = 0;
	for (auto& i : command) {
		if (i == 'U') {
			if (!Map[{x, y + 1}]) {
				y++;
			}
		}
		else if (i == 'D') {
			if (!Map[{x, y - 1}]) {
				y--;
			}
		}
		else if (i == 'R') {
			if (!Map[{x + 1, y}]) {
				x++;
			}
		}
		else if (i == 'L') {
			if (!Map[{x - 1, y}]) {
				x--;
			}
		}
	}
	cout << x << ' ' << y;
	return 0;
}
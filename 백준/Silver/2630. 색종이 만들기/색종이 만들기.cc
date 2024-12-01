#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
ll n = 0, m = 0, k = 0;
ll Map[129][129];
void dfs(ll startx, ll starty, ll n) {
	bool a = false;
	bool b = false;
	for (int i = starty; i < starty + n; i++) {
		for (int j = startx; j < startx + n; j++) {
			if (Map[i][j]) {
				a = true;
			}
			else {
				b = true;
			}
		}
	}
	if (a && !b) {
		m++;
		return;
	}
	else if (!a && b) {
		k++;
		return;
	}
	dfs(startx, starty, n / 2);
	dfs(startx, starty + n / 2, n / 2);
	dfs(startx + n / 2, starty, n / 2);
	dfs(startx + n / 2, starty + n / 2, n / 2);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Map[i][j];
		}
	}
	dfs(0, 0, n);
	cout << k << '\n';
	cout << m;
	return 0;
}
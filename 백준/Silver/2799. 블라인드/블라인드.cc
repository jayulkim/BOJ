#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
char Map[601][601];
ll ary[6];
vector<string>v = { "................", "****............", "********........", "************....", "****************" };
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	for (int i = 0; i < 6 + 5 * (n - 1); i++) {
		for (int j = 0; j < 6 + 5 * (m - 1); j++) {
			cin >> Map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ll starty = 1 + 5 * i, startx = 1 + 5 * j;
			string temp = "";
			for (int k = starty; k < starty + 4; k++) {
				for (int u = startx; u < startx + 4; u++) {
					temp += Map[k][u];
				}
			}
			for (int k = 0; k < 5; k++) {
				if (v[k] == temp) {
					ary[k + 1]++;
					break;
				}
			}
		}
	}
	for (int i = 1; i < 6; i++) {
		cout << ary[i] << ' ';
	}
	return 0;
}
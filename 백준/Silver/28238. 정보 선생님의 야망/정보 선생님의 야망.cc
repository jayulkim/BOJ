#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<vector<ll>>Map(1000001, vector<ll>(6, 0));
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> Map[i][j];
		}
	}
	ll result = 0;
	vector<ll>v(6, 0);
	for (int i = 1; i <= 4; i++) {
		for (int j = i + 1; j <= 5; j++) {
			ll temp = 0;
			vector<ll>vv(6, 0);
			for (int k = 1; k <= 5; k++) {
				if (k == i || k == j) {
					vv[k] = 1;
				}
			}
			for (int k = 1; k <= n; k++) {
				if (Map[k][i] && Map[k][j]) {
					temp++;
				}
			}
			if (temp >= result) {
				result = temp;
				v = vv;
			}
		}
	}
	cout << result << '\n';
	for (int i = 1; i <= 5; i++) {
		cout << v[i] << ' ';
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
ll n = 0, m = 0, k = 0;
vector<vector<ll>>leftdp(1002, vector<ll>(1002, -1e12));
vector<vector<ll>>rightdp(1002, vector<ll>(1002, -1e12));
vector<vector<ll>>Map(1002, vector<ll>(1002, -1e12));
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> Map[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			leftdp[i][j] = max({ Map[i][j], leftdp[i - 1][j] + Map[i][j], leftdp[i][j - 1] + Map[i][j] });
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {
			rightdp[i][j] = max({ Map[i][j], rightdp[i - 1][j] + Map[i][j], rightdp[i][j + 1] + Map[i][j] });
		}
	}
	ll Max = -LLONG_MAX;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			Max = max(Max, leftdp[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			Max = max(Max, rightdp[i][j]);
		}
	}
	cout << Max;
	return 0;
}
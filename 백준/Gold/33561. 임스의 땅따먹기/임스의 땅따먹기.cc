#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll Map[501][501];
ll sum[501][501];
ll zero[501][501];
ll sumzero[501][501];
int main(void) {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> Map[i][j];
			if (!Map[i][j]) {
				zero[i][j] = 1;
			}
		}
	}
	cin >> m;
	vector<ll>v(m + 1);
	vector<ll>vv(m + 1);
	for (int i = 1; i <= m; i++) {
		cin >> v[i];
	}
	sort(v.begin() + 1, v.begin() + m + 1, greater<ll>());
	for (int i = 1; i <= m; i++) {
		vv[i] = vv[i - 1] + v[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + Map[i][j];
			sumzero[i][j] = sumzero[i][j - 1] + sumzero[i - 1][j] - sumzero[i - 1][j - 1] + zero[i][j];
		}
	}
	ll Max = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				ll dy = j - i;
				ll dx = k - i;
				if (dy >= 0 && dx >= 0 && sumzero[j][k] - sumzero[dy][k] - sumzero[j][dx] + sumzero[dy][dx] <= m) {
					Max = max(Max, sum[j][k] - sum[dy][k] - sum[j][dx] + sum[dy][dx] + vv[sumzero[j][k] - sumzero[dy][k] - sumzero[j][dx] + sumzero[dy][dx]]);
				}
			}
		}
	}
	cout << Max;
	return 0;
}
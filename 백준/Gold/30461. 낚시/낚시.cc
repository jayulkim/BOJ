#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll Map[2001][2001];
ll sum[2001][2001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> Map[i][j];
		}
	}
	for (int i = 1; i <= m; i++) {
		sum[1][i] = Map[1][i];
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sum[i][j] = sum[i - 1][j] + sum[i - 1][j - 1] + Map[i][j];
			if (i - 2 >= 1) {
				sum[i][j] -= sum[i - 2][j - 1];
			}
		}
	}
	for (int i = 0; i < k; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		cout << sum[a][b] << '\n';
	}
	return 0;
}
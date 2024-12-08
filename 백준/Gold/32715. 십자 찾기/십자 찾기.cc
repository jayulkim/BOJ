#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll Map[2501][2501];
ll sum[2501][2501];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> Map[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + Map[i][j];
		}
	}
	ll count = 0;
	for (int i = k + 1; i < n - k + 1; i++) {
		for (int j = k + 1; j < m - k + 1; j++) {
			if (2 * k + 1 == sum[i][j + k] - sum[i][j - k - 1] - sum[i - 1][j + k] + sum[i - 1][j - k - 1] && 2 * k + 1 == sum[i + k][j] - sum[i - k - 1][j] - sum[i + k][j - 1] + sum[i - k - 1][j - 1]) {
				count++;
			}
		}
	}
	cout << count;
	return 0;
}
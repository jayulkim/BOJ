#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
#define num 1e11
ll n = 0, m = 0, k = 0;
vector<vector<ll>>dp(200001, vector<ll>(38, -(1LL << 38)));
vector<ll>v(200001);
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	if (m > 37) {
		cout << "MEGA";
		return 0;
	}
	dp[0][0] = k;
	for (int i = 1; i <= n; i++) {
		ll temp = 0;
		for (int j = 0; j <= m; j++) {
			if (!j) {
				if (dp[i - 1][j] + v[i] > 0) {
					dp[i][j] = dp[i - 1][j] + v[i];
				}
			}
			else {
				if (dp[i - 1][j] + v[i] > 0) {
					dp[i][j] = dp[i - 1][j] + v[i];
				}
				if (dp[i - 1][j - 1] * 2 > 0) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] * 2);
				}
			}
			if (dp[i][j] > (1LL << 38)) {
				cout << "MEGA";
				return 0;
			}
			temp = max(temp, dp[i][j]);
		}
		if (temp <= 0) {
			cout << -1;
			return 0;
		}
	}
	ll Max = 0;
	for (int i = 0; i <= m; i++) {
		Max = max(Max, dp[n][i]);
	}
	if (Max > num) {
		cout << "MEGA";
		return 0;
	}
	cout << Max;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll dp[100001][5][5];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<ll>v;
	while (1) {
		ll num = 0;
		cin >> num;
		if (!num) {
			break;
		}
		v.push_back(num);
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j <= 4; j++) {
			for (int k = 0; k <= 4; k++) {
				dp[i][j][k] = 987654321;
			}
		}
	}
	dp[0][0][v[0]] = 2;
	dp[0][v[0]][0] = 2;
	for (int i = 1; i < v.size(); i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				if (j != v[i]) {
					if (!k) {
						dp[i][j][v[i]] = min(dp[i][j][v[i]], dp[i - 1][j][k] + 2);
					}
					else if (k == v[i]) {
						dp[i][j][v[i]] = min(dp[i][j][v[i]], dp[i - 1][j][k] + 1);
					}
					else if (llabs(k - v[i]) != 2) {
						dp[i][j][v[i]] = min(dp[i][j][v[i]], dp[i - 1][j][k] + 3);
					}
					else {
						dp[i][j][v[i]] = min(dp[i][j][v[i]], dp[i - 1][j][k] + 4);
					}
				}
			}
			for (int k = 0; k < 5; k++) {
				if (k != v[i]) {
					if (!j) {
						dp[i][v[i]][k] = min(dp[i][v[i]][k], dp[i - 1][j][k] + 2);
					}
					else if (j == v[i]) {
						dp[i][v[i]][k] = min(dp[i][v[i]][k], dp[i - 1][j][k] + 1);
					}
					else if (llabs(j - v[i]) != 2) {
						dp[i][v[i]][k] = min(dp[i][v[i]][k], dp[i - 1][j][k] + 3);
					}
					else {
						dp[i][v[i]][k] = min(dp[i][v[i]][k], dp[i - 1][j][k] + 4);
					}
				}
			}
		}
	}
	ll Min = LLONG_MAX;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			Min = min(Min, dp[v.size() - 1][i][j]);
		}
	}
	cout << Min;
	return 0;
}
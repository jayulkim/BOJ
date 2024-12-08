#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<vector<ll>>dp(2, vector<ll>(200001, -1));
vector<vector<ll>>Map(2, vector<ll>(200001, -1));
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Map[i][j];
		}
	}
	dp[0][0] = Map[0][0];
	dp[1][0] = Map[0][0] + Map[1][0];
	dp[0][1] = max({ Map[0][0] + Map[0][1], Map[0][0] + Map[0][1] + Map[1][0] + Map[1][1], Map[0][0] + Map[1][0] + Map[0][1], Map[0][0] + Map[0][1] + Map[1][1] });
	dp[1][1] = max({ Map[0][0] + Map[1][0] + Map[1][1], Map[0][0] + Map[0][1] + Map[1][1], Map[0][0] + Map[1][0] + Map[1][1] + Map[0][1] });
	for (int i = 2; i < n; i++) {
		dp[0][i] = max({ dp[0][i - 2] + Map[0][i - 1] + Map[0][i], dp[0][i - 2] + Map[0][i - 1] + Map[1][i - 1] + Map[0][i], dp[0][i - 2] + Map[0][i - 1] + Map[0][i] + Map[1][i], dp[0][i - 2] + Map[0][i - 1] + Map[1][i - 1] + Map[0][i] + Map[1][i], dp[1][i - 2] + Map[1][i - 1] + Map[1][i] + Map[0][i], dp[1][i - 2] + Map[1][i - 1] + Map[0][i - 1] + Map[0][i], dp[1][i - 2] + Map[1][i - 1] + Map[0][i - 1] + Map[0][i] + Map[1][i] });
		dp[1][i] = max({ dp[0][i - 2] + Map[0][i - 1] + Map[0][i] + Map[1][i], dp[0][i - 2] + Map[0][i - 1] + Map[1][i - 1] + Map[1][i], dp[0][i - 2] + Map[0][i - 1] + Map[1][i - 1] + Map[1][i] + Map[0][i], dp[1][i - 2] + Map[1][i - 1] + Map[1][i], dp[1][i - 2] + Map[1][i - 1] + Map[0][i - 1] + Map[1][i], dp[1][i - 2] + Map[1][i - 1] + Map[1][i] + Map[0][i], dp[1][i - 2] + Map[1][i - 1] + Map[0][i - 1] + Map[0][i] + Map[1][i] });
	}
	cout << dp[1][n - 1];
	return 0;
}
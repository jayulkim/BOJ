#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll dp[26][26];
ll Map[26][26];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> Map[i][j];
		}
	}
	dp[1][1] = Map[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + Map[i][j];
		}
	}
	ll Max = 0;
	for (int i = 1; i <= n; i++) {
		Max = max(Max, dp[n][i]);
	}
	cout << Max;
	return 0;
}
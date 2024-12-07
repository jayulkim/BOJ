#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll dp[10000001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	dp[4] = 1;
	dp[5] = 1;
	dp[6] = 2;
	dp[7] = 3;
	dp[8] = 5;
	dp[9] = 6;
	dp[10] = 8;
	dp[11] = 10;
	dp[12] = 13;
	for (int i = 13; i <= 10000000; i++) {
		if (i % 4 == 1) {
			dp[i] = dp[i - 1] + i / 4 - 1;
		}
		else {
			dp[i] = dp[i - 1] + i / 4;
		}
	}
	cin >> n;
	cout << dp[n];
	return 0;
}
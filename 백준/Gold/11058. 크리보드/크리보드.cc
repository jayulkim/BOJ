#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>dp(101);
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (int i = 4; i <= 100; i++) {
		ll Max = 0;
		for (int j = i - 3; j >= 1; j--) {
			Max = max(Max, dp[j] * (i - j - 1));
		}
		dp[i] = max(Max, dp[i - 1] + 1);
	}
	cin >> n;
	cout << dp[n];
	return 0;
}
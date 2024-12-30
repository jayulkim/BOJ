#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll dp[51];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= 50; i++) {
		dp[i] = (dp[i - 1] % 1000000007 + dp[i - 2] % 1000000007 + 1) % 1000000007;
	}
	cin >> n;
	cout << dp[n];
	return 0;
}
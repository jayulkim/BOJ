#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
ll n = 0, m = 0, k = 0;
vector<ll>dp(1000001);
#define mod 1000000009
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 1000000; i++) {
		dp[i] = ((dp[i - 1] % mod) + (dp[i - 2] % mod) + (dp[i - 3] % mod)) % mod;
	}
	ll num = 0;
	cin >> num;
	while (num--) {
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}
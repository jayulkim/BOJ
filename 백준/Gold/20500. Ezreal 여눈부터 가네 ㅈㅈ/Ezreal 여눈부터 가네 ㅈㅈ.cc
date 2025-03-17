#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
#define mod 1000000007
ll dp[1516];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= 1515; i++) {
		dp[i] = ((dp[i - 1] % mod) + 2 * (dp[i - 2] % mod)) % mod;
	}
	cin >> n;
	cout << dp[n] % mod;
	return 0;
}
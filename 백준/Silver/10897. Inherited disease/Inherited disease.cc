#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
#define mod 1000000007
ll ary[101];
ll sum[101];
ll v[101];
ll dp[101];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ary[0] = 1;
	ary[1] = 1;
	for (ll i = 2; i <= 100; i++) {
		ary[i] = (((ary[i - 1] % mod) * i) % mod);
	}
	sum[0] = ary[0];
	for (int i = 1; i <= 100; i++) {
		sum[i] = (sum[i - 1] % mod + ary[i] % mod) % mod;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	ll a = 0;
	for (ll i = 0; i < n; i++) {
		if (!i) {
			cout << 1 << '\n';
			a = 1;
		}
		else {
			cout << ((sum[i] - 1) + (((i + 1) * (a - 1)) % mod + v[i] % mod)) % mod << '\n';
			a = (((i + 1) * (a - 1)) % mod + v[i] % mod);
		}
	}
	return 0;
}
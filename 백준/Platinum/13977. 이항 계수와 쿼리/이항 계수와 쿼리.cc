#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll up[4000001];
ll powmod(ll x, ll y, ll num) {
	x %= num;
	ll result = 1;
	while (y > 0) {
		if (y % 2 == 1) {
			result *= x;
			result %= num;
		}
		x *= x;
		x %= num;
		y /= 2;
	}
	return result;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	up[1] = 1;
	for (ll i = 2; i <= 4000000; i++) {
		up[i] = ((i % 1000000007) * (up[i - 1] % 1000000007)) % 1000000007;
	}
	int num = 0;
	cin >> num;
	while (num--) {
		ll n = 0, k = 0;
		cin >> n >> k;
		if (k == 0 || k == n) {
			cout << 1 << '\n';
		}
		else {
			if (k > n / 2) {
				k = n - k;
			}
			cout << ((up[n] % 1000000007) * powmod(((up[k] % 1000000007) * (up[n - k] % 1000000007)) % 1000000007, 1000000005, 1000000007)) % 1000000007 << '\n';
		}
	}
	return 0;
}
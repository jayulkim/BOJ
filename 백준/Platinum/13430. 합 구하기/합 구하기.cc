#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
	ll k = 0, n = 0;
	cin >> k >> n;
	ll up = 1;
	ll count = n + k;
	for (ll i = 1; i <= k + 1; i++) {
		up = ((up % 1000000007) * count) % 1000000007;
		count--;
	}
	ll down = 1;
	for (ll i = 2; i <= k + 1; i++) {
		down = ((down % 1000000007) * i) % 1000000007;
	}
	cout << ((up % 1000000007) * (powmod(down % 1000000007, 1000000005, 1000000007) % 1000000007)) % 1000000007;
	return 0;
}
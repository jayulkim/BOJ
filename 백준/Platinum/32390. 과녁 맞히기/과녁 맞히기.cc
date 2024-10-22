#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll addmod(ll x, ll y, ll num) {
	if (x >= num - y) {
		return x - (num - y);
	}
	else {
		return x + y;
	}
}
ll mulmod(ll x, ll y, ll num) {
	ll result = 0;
	while (y > 0) {
		if (y % 2) {
			result = addmod(result, x, num);
		}
		x = addmod(x, x, num);
		y /= 2;
	}
	return result;
}
ll powmod(ll x, ll y, ll num) {
	ll result = 1;
	while (y > 0) {
		if (y % 2) {
			result = mulmod(result, x, num);
		}
		x = mulmod(x, x, num);
		y /= 2;
	}
	return result;
}
ll fac(ll n, ll num) {
	ll result = 1;
	for (ll i = 2; i <= n; i++) {
		result = mulmod(result, i, num);
	}
	return result;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	ll up = mulmod(fac(n, 1000000007), powmod(2, n - m, 1000000007), 1000000007);
	ll down = 1;
	for (int i = 0; i < m; i++) {
		ll num = 0;
		cin >> num;
		down = mulmod(down, fac(num, 1000000007), 1000000007);
	}
	cout << mulmod(up, powmod(down, 1000000005, 1000000007), 1000000007);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll addmod(ll x, ll y, ll num) {
	if (x >= (num - y)) {
		return x - (num - y);
	}
	else {
		return x + y;
	}
}
ll mulmod(ll x, ll y, ll num) {
	x %= num;
	ll result = 0;
	while (y > 0) {
		if (y % 2 == 1) {
			result = addmod(result, x, num);
		}
		x = addmod(x, x, num);
		y /= 2;
	}
	return result;
}
ll powmod(ll x, ll y, ll num) {
	x %= num;
	ll result = 1;
	while (y > 0) {
		if (y % 2 == 1) {
			result = mulmod(result, x, num);
		}
		x = mulmod(x, x, num);
		y /= 2;
	}
	return result;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	cout << powmod(n, m, 1000000007);
	return 0;
}
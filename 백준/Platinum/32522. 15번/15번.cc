#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
#define mod 1000000007
ll n = 0, m = 0, k = 0;
ll addmod(ll x, ll y, ll num) {
	if (x >= (num - y)) {
		return x - (num - y);
	}
	return x + y;
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
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	ll plus = 0;
	ll temp = 1;
	for (int i = 1; i <= m; i++) {
		temp = addmod(temp, powmod(n, i, mod), mod);
		if ((i - 1) % n && i - 1 != 1) {
			plus = addmod(plus, i - 1, mod);
		}
		temp = addmod(temp, plus, mod);
		cout << temp << '\n';
		plus = mulmod(plus, n, mod);
	}
	return 0;
}

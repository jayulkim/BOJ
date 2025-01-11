#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll addmod(ll x, ll y, ll num) {
	if (x >= num - y) {
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
	while (1) {
		cin >> n >> m;
		if (!n && !m) {
			break;
		}
		ll num = powmod(m, n, n);
		bool find = false;
		if (num == m) {
			for (ll i = 2; i <= n / i; i++) {
				if (n % i == 0) {
					find = true;
					cout << "yes" << '\n';
					break;
				}
			}
		}
		if (!find) {
			cout << "no" << '\n';
		}
	}
	return 0;
}
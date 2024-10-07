#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
ll powmod(ll x, ll y, ll num) {
	x %= num;
	ll result = 1;
	while (y > 0) {
		if (y % 2 == 1) {
			result *= (x % num);
			result %= num;
		}
		x *= (x % num);
		x %= num;
		y /= 2;
	}
	return result;
}
ll comb(ll x, ll y, ll num) {
	ll u = 1, d = 1;
	if (y > x) {
		return 0;
	}
	if (y == 0 || x == y) {
		return 1;
	}
	for (int i = 0; i < y; i++) {
		u *= x;
		x--;
		u %= num;
	}
	for (ll i = 1; i <= y; i++) {
		d *= i;
		d %= num;
	}
	return ((u % num) * powmod(d, num - 2, num)) % num;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	vector<ll>up;
	vector<ll>down;
	while (n > 0) {
		up.push_back(n % k);
		n /= k;
	}
	while (m > 0) {
		down.push_back(m % k);
		m /= k;
	}
	while (down.size() < up.size()) {
		down.push_back(0);
	}
	ll result = 1;
	for (int i = 0; i < up.size(); i++) {
		result *= comb(up[i], down[i], k);	
		result %= k;
	}
	cout << result % k;
	return 0;
}
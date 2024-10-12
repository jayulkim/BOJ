#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<ll, ll> pll;
ll gcd(ll x, ll y) {
	ll temp = x % y;
	while (temp > 0) {
		x = y;
		y = temp;
		temp = x % y;
	}
	return y;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll a = 0, b = 0;
	cin >> a >> b;
	for (int i = 0; i < gcd(a, b); i++) {
		cout << 1;
	}
	return 0;
}
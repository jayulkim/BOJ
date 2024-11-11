#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) {
	ll temp = a % b;
	while (temp > 0) {
		a = b;
		b = temp;
		temp = a % b;
	}
	return b;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	ll count = 0;
	for (int i = 1; i <= m; i++) {
		if (i != n && (gcd(i, n) == 1 || gcd(i, n) == 2)) {
			count++;
		}
	}
	cout << count;
	return 0;
}
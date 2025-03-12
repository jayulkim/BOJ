#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, char> plc;
typedef pair<string, ll> psl;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll, ll, ll, ll, ll, ll>llllllll;
ll n = 0, m = 0, k = 0;
ll gcd(ll a, ll b) {
	ll temp = a % b;
	while (temp > 0) {
		a = b;
		b = temp;
		temp = a % b;
	}
	return b;
}
pll eea(ll a, ll b) {
	ll r1 = a, r2 = b, s1 = 1, t1 = 0, s2 = 0, t2 = 1;
	while (r2 > 0) {
		ll x = r1 / r2;
		ll y = r1 % r2;
		r1 = r2;
		r2 = y;
		ll s = s1 - x * s2;
		s1 = s2;
		s2 = s;
		ll t = t1 - x * t2;
		t1 = t2;
		t2 = t;
	}
	return { s1, t1 };
}
int main(void) { 
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	while (num--) {
		cin >> n >> m;
		ll temp = eea(n, m).second;
		if (temp > 1000000000 || gcd(n, m) != 1) {
			cout << "IMPOSSIBLE" << '\n';
		}
		else {
			if (n == 1 && n < m) {
				cout << 1 << '\n';
				continue;
			}
			if (n % m == 0) {
				if (n / m + 1 <= 1000000000) {
					cout << n / m + 1 << '\n';
				}
				else {
					cout << "IMPOSSIBLE" << '\n';
				}
				continue;
			}
			cout << (temp + n) % n << '\n';
		}
	}
	return 0;
}
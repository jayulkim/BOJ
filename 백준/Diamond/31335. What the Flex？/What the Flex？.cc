#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, char> plc;
typedef pair<string, ll> psl;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll, ll, ll, ll, ll, ll>llllllll;
unsigned long long n = 0, m = 0, k = 0;
ll ary[14] = { 2, 3, 5, 7, 11, 13, 17,  19, 23, 29, 31, 37, 61, 73 };
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
bool millerlabin(ll x, ll ary) {
	if (x == 1) {
		return false;
	}
	if (x == 2) {
		return true;
	}
	if (x == ary) {
		return true;
	}
	ll num = x - 1;
	while (1) {
		ll temp = powmod(ary, num, x);
		if (temp == x - 1) {
			return true;
		}
		if (num % 2 == 0) {
			num /= 2;
		}
		else {
			if (temp == x - 1 || temp == 1) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}
bool isprime(ll x) {
	for (int i = 0; i < 14; i++) {
		if (!millerlabin(x, ary[i])) {
			return false;
		}
	}
	return true;
}
ll Random(ll x, ll c, ll num) {
	return (mulmod(x, x, num) + c) % num;
}
ll gcd(ll a, ll b) {
	ll temp = a % b;
	while (temp > 0) {
		a = b;
		b = temp;
		temp = a % b;
	}
	return b;
}
ll pollardrho(ll x) {
	if (x % 2 == 0) {
		return 2;
	}
	if (isprime(x)) {
		return x;
	}
	ll a = (rand() % (x - 2)) + 1;
	ll b = a;
	ll c = (rand() % 3) * 2 - 1;
	ll d = 1;
	while (gcd(d, x) == 1) {
		a = Random(a, c, x);
		b = Random(b, c, x);
		b = Random(b, c, x);
		d = llabs(a - b);
		if (gcd(d, x) == x) {
			return pollardrho(gcd(d, x));
		}
	}
	if (!isprime(gcd(d, x))) {
		return pollardrho(gcd(d, x));
	}
	return gcd(d, x);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	ll a = n;
	map<ll, ll>Map;
	while (n > 1) {
		ll temp = pollardrho(n);
		Map[temp]++;
		n /= temp;
	}
	vector<pll>v;
	for (auto& i : Map) {
		v.push_back({ i.first, i.second });
	}
	sort(v.begin(), v.end(), greater<pll>());
	for (int i = 0; i < v.size(); i++) {
		if (a * v[i].first <= m) {
			cout << (unsigned long long)a * (unsigned long long)v[i].first;
			return 0;
		}
		while (a % v[i].first == 0) {
			a /= v[i].first;
		}
		a *= v[i].first;
	}
	cout << -1;
	return 0;
}
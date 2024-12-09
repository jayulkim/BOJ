#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
unsigned long long n = 0, m = 0, k = 0;
ll ary[12] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
ll addmod(ll x, ll y, ll num) {
	if (x >= (num - y)) {
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
ll gcd(ll x, ll y) {
	ll temp = x % y;
	while (temp > 0) {
		x = y;
		y = temp;
		temp = x % y;
	}
	return y;
}
ll Random(ll x, ll c, ll num) {
	return (mulmod(x, x, num) + c) % num;
}
bool millerlabin(ll x, ll a) {
	if (x == 1) {
		return false;
	}
	if (x == 2) {
		return true;
	}
	if (x == a) {
		return true;
	}
	ll num = x - 1;
	while (1) {
		ll temp = powmod(a, num, x);
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
	for (int i = 0; i < 12; i++) {
		if (!millerlabin(x, ary[i])) {
			return false;
		}
	}
	return true;
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
ll power(ll x, ll y) {
	ll result = 1;
	while (y > 0) {
		if (y % 2) {
			result *= x;
		}
		x *= x;
		y /= 2;
	}
	return result;
}
map<ll, ll>Map;
map<ll, ll>a;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	ll result = 1;
	while (n > 1) {
		ll temp = pollardrho(n);
		if (!Map[temp]) {
			result *= temp;
		}
		Map[temp]++;
		n /= temp;
	}
	ll temp = Map.begin()->second;
	for (auto& i : Map) {
		temp = gcd(temp, i.second);
	}
	for (auto& i : Map) {
		a[i.first] = i.second / temp;
	}
	for (ll i = 1; i <= 62; i++) {
		bool find = false;
		for (auto& j : a) {
			ll temp = i * j.second;
			for (auto& k : a) {
				temp *= (i * k.second + 1);
			}
			if (temp != Map[j.first]) {
				if (temp > Map[j.first]) {
					cout << -1;
					return 0;
				}
				find = true;
				break;
			}
		}
		if (!find) {
			ll result = 1;
			for (auto& j : a) {
				result *= pow(j.first, i * j.second);
			}
			cout << (unsigned long long)result;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
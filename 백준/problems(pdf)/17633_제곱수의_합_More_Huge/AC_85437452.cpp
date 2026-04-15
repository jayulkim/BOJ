#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ary[12] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
ll mulmod(ll x, ll y, ll num) {
	ll result = 0;
	while (y > 0) {
		if (y % 2) {
			result += (x % num);
			result %= num;
		}
		x += (x % num);
		x %= num;
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
bool millerlabin(ll x, ll num) {
	if (x == 1) {
		return false;
	}
	if (x == 2) {
		return true;
	}
	if (x == num) {
		return true;
	}
	ll num1 = x - 1;
	while (1) {
		ll temp = powmod(num, num1, x);
		if (temp == x - 1) {
			return true;
		}
		if (num1 % 2 == 0) {
			num1 /= 2;
		}
		else {
			if (temp == 1 || temp == x - 1) {
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
ll Random(ll a, ll c, ll num) {
	return (mulmod(a, a, num) + c) % num;
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
		a = Random(a, c, x) % x;
		b = Random(b, c, x) % x;
		b = Random(b, c, x) % x;
		d = llabs(b - a);
		if (gcd(d, x) == x) {
			return pollardrho(gcd(d, x));
		}
	}
	if (!isprime(gcd(d, x))) {
		return pollardrho(gcd(d, x));
	}
	return gcd(d, x);
}
map<ll, ll>Map;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	cin >> n;
	ll result = n;
	while (n > 1) {
		ll temp = pollardrho(n);
		Map[temp]++;
		n /= temp;
	}
	bool find = false;
	for (auto i = Map.begin(); i != Map.end(); i++) {
		if (i->second % 2) {
			find = true;
			break;
		}
	}
	if (!find) {
		cout << 1;
		return 0;
	}
	find = false;
	for (auto i = Map.begin(); i != Map.end(); i++) {
		if (i->first % 4 == 3) {
			if (i->second % 2) {
				find = true;
				break;
			}
		}
	}
	if (!find) {
		cout << 2;
		return 0;
	}
	while (result % 4 == 0) {
		result /= 4;
	}
	if (result % 8 == 7) {
		cout << 4;
		return 0;
	}
	cout << 3;
	return 0;
}
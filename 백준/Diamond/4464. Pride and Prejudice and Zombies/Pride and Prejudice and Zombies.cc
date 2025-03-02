#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;
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
ll Pow(ll x, ll y) {
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
		return (ll)2;
	}
	if (isprime(x)) {
		return x;
	}
	ll a = ((ll)rand() % (x - (ll)2)) + (ll)1;
	ll b = a;
	ll c = ((ll)rand() % (ll)3) * (ll)2 - (ll)1;
	ll d = (ll)1;
	while (gcd(d, x) == (ll)1) {
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
	while (1) {
		cin >> n;
		if (!n) {
			break;
		}
		map<ll, ll>soinsoo;
		vector<ll>soinsoosoinsoo;
		string str = to_string(n);
		sort(str.begin(), str.end());
		if (str.length() % 2) {
			cout << n << ": " << "no" << '\n';
			continue;
		}
		m = n;
		while (n > 1) {
			ll temp = pollardrho(n);
			n /= temp;
			soinsoo[temp]++;
			soinsoosoinsoo.push_back(temp);
		}
		sort(soinsoosoinsoo.begin(), soinsoosoinsoo.end());
		vector<ll>yaksoo = { 1 };
		for (auto& i : soinsoo) {
			ll size = yaksoo.size();
			for (int j = 1; j <= i.second; j++) {
				for (int k = 0; k < size; k++) {
					yaksoo.push_back(yaksoo[k] * powmod(i.first, j, LLONG_MAX));
				}
			}
		}
		bool findfind = false;
		for (auto& i : yaksoo) {
			string a = to_string(i);
			string b = to_string(m / i);
			string ab = a + b;
			sort(ab.begin(), ab.end());
			if (ab != str) {
				continue;
			}
			if (a.length() != str.length() / 2 || b.length() != str.length() / 2) {
				continue;
			}
			bool find = false;
			for (int j = 0; j < a.length() - 1; j++) {
				if (a[j] == '0' && a[j + 1] == '0') {
					find = true;
					break;
				}
			}
			for (int j = 0; j < b.length() - 1; j++) {
				if (b[j] == '0' && b[j + 1] == '0') {
					find = true;
					break;
				}
			}
			if (find) {
				continue;
			}
			vector<ll>soinsoosoinsoosoinsoo;
			ll aa = i, bb = m / i;
			while (aa > 1) {
				ll temp = pollardrho(aa);
				aa /= temp;
				soinsoosoinsoosoinsoo.push_back(temp);
			}
			while (bb > 1) {
				ll temp = pollardrho(bb);
				bb /= temp;
				soinsoosoinsoosoinsoo.push_back(temp);
			}
			sort(soinsoosoinsoosoinsoo.begin(), soinsoosoinsoosoinsoo.end());
			if (soinsoosoinsoosoinsoo == soinsoosoinsoo) {
				cout << m << ": " << "yes\n";
				findfind = true;
				break;
			}
		}
		if (!findfind) {
			cout << m << ": " << "no\n";
		}
	}
	return 0;
}
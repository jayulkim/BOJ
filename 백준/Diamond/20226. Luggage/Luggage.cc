#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
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
map<ll, ll>soinsoomap;
vector<ll>div(ll x) {
	vector<ll>result;
	while (x > 1) {
		ll temp = pollardrho(x);
		soinsoomap[temp]++;
		result.push_back(temp);
		x /= temp;
	}
	sort(result.begin(), result.end());
	return result;
}
vector<ll>yaksoolist(ll x) {
	vector<ll>soinsoo = div(x);
	vector<ll>result = { 1 };
	for (auto i = soinsoomap.begin(); i != soinsoomap.end(); i++) {
		ll temp = result.size();
		for (int j = 1; j <= i->second; j++) {
			for (int k = 0; k < temp; k++) {
				result.push_back(result[k] * powmod(i->first, j, LLONG_MAX));
			}
		}
	}
	map<ll, ll>().swap(soinsoomap);
	sort(result.begin(), result.end());
	return result;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		ll n = 0;
		cin >> n;
		if (!n) {
			break;
		}
		vector<ll>yaksoo = yaksoolist(n);
		ll result = LLONG_MAX;
		ll a = sqrt(n);
		for (auto& i : yaksoo) {
			if (i > a) {
				break;
			}
			ll temp = sqrt(n / i);
			ll b = lower_bound(yaksoo.begin(), yaksoo.end(), temp) - yaksoo.begin();
			for (int j = max((ll)0, b - 15); j < min((ll)yaksoo.size(), b + 15); j++) {
				if (i * yaksoo[j] * ((n / i) / yaksoo[j]) == n) {
					result = min(result, i + yaksoo[j] + (n / i) / yaksoo[j]);
				}
			}
		}
		cout << result << '\n';
	}
	return 0;
}
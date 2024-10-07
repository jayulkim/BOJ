#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ary[3] = { 2, 3, 61 };
ll mulmod(ll x, ll y, ll num) {
	return (__int128)x * y % num;
}
ll powmod(ll x, ll y, ll num) {
	ll result = 1;
	x %= num;
	while (y > 0) {
		if (y % 2 == 1) {
			result = mulmod(result, x, num);
			result %= num;
		}
		x = mulmod(x, x, num);
		x %= num;
		y /= 2;
	}
	return result;
}
bool millerlabin(ll x, ll y) {
	if (x == 1) {
		return false;
	}
	if (x == 2) {
		return true;
	}
	if (x == y) {
		return true;
	}
	ll num = x - 1;
	while (1) {
		ll temp = powmod(y, num, x) % x;
		if (temp == x - 1 || temp % x == 1) {
			return true;
		}
		else {
			if (num % 2 == 0) {
				num /= 2;
			}
			else {
				if (temp % x == 1 || temp == x - 1) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
}
bool isprime(ll x) {
	for (int i = 0; i < 3; i++) {
		if (!millerlabin(x, ary[i])) {
			return false;
		}
	}
	return true;
}
bool ispalindrome(ll x) {
	if (x == 11) {
		return true;
	}
	string str = to_string(x);
	if (str.length() % 2 == 0) {
		return false;
	}
	for (int i = 0; i < str.length() / 2; i++) {
		if (str[i] != str[str.length() - i - 1]) {
			return false;
		}
	}
	return true;
}
ll getpalindrome(ll x) {
	string result = to_string(x);
	for (int i = result.length() - 2; i >= 0; i--) {
		result += result[i];
	}
	return stoll(result);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll start = 0, end = 0;
	int count = 0;
	vector<ll>v;
	vector<ll>result;
	for (ll i = 2; i < 1000000; i++) {
		if ((i == 2 || i == 3 || i == 5 || i == 7)) {
			v.push_back(i);
		}
		else if (i >= 10 && ispalindrome(i)) {
			v.push_back(i);
		}
		if (i >= 1000) {
			ll temp = getpalindrome(i);
			v.push_back(temp);
		}
	}
	for (auto& i : v) {
		if (isprime(i)) {
			result.push_back(i);
		}
	}
	cin >> start >> end;
	for (auto& i : result) {
		if (start <= i && i <= end) {
			count++;
		}
	}
	cout << count;
	return 0;
}
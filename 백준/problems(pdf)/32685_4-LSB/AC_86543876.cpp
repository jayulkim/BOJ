#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll mypow(ll x, ll y) {
	ll result = 1;
	for (int i = 1; i <= y; i++) {
		result *= x;
	}
	return result;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<ll>v;
	vector<ll>vv;
	vector<ll>vvv;
	cin >> n >> m >> k;
	while (n > 0) {
		v.push_back(n % 2);
		n /= 2;
	}
	while (m > 0) {
		vv.push_back(m % 2);
		m /= 2;
	}
	while (k > 0) {
		vvv.push_back(k % 2);
		k /= 2;
	}
	while (v.size() < 4) {
		v.push_back(0);
	}
	while (vv.size() < 4) {
		vv.push_back(0);
	}
	while (vvv.size() < 4) {
		vvv.push_back(0);
	}
	string result = "";
	for (int i = 0; i < 4; i++) {
		result += to_string(vvv[i]);
	}
	for (int i = 0; i < 4; i++) {
		result += to_string(vv[i]);
	}
	for (int i = 0; i < 4; i++) {
		result += to_string(v[i]);
	}
	ll a = 0;
	for (int i = 0; i < 12; i++) {
		if (result[i] == '1') {
			a += mypow(2, i);
		}
	}
	string b = to_string(a);
	while (b.length() < 4) {
		b = '0' + b;
	}
	cout << b;
	return 0;
}
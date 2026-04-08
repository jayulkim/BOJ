#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<ll>prime;
	vector<ll>vi(5001, 0);
	for (int i = 2; i * i <= 5000; i++) {
		if (!vi[i]) {
			for (int j = i * i; j <= 5000; j += i) {
				vi[j] = 1;
			}
		}
	}
	for (int i = 2; i <= 5000; i++) {
		if (!vi[i]) {
			prime.push_back(i);
		}
	}
	ll num = 0;
	cin >> num;
	while (num--) {
		ll a = 0, b = 0, c = 0, d = 0;
		cin >> a >> b >> c >> d;
		vector<ll>aup(5001, 0);
		vector<ll>cup(5001, 0);
		vector<ll>adown(5001, 0);
		vector<ll>cdown(5001, 0);
		for (auto& i : prime) {
			for (int j = i; j <= a; j *= i) {
				aup[i] += a / j;
			}
		}
		for (auto& i : prime) {
			for (int j = i; j <= c; j *= i) {
				cup[i] += c / j;
			}
		}
		for (auto& i : prime) {
			for (int j = i; j <= b; j *= i) {
				adown[i] += b / j;
			}
		}
		for (auto& i : prime) {
			for (int j = i; j <= a - b; j *= i) {
				adown[i] += (a - b) / j;
			}
		}
		for (auto& i : prime) {
			for (int j = i; j <= d; j *= i) {
				cdown[i] += d / j;
			}
		}
		for (auto& i : prime) {
			for (int j = i; j <= c - d; j *= i) {
				cdown[i] += (c - d) / j;
			}
		}
		ll result = 1;
		for (int i = 2; i <= max(a, c); i++) {
			if ((aup[i] - adown[i] > 0) && (cup[i] - cdown[i] > 0)) {
				result = 0;
				break;
			}
		}
		cout << result << '\n';
	}
	return 0;
}
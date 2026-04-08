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
		ll result = 1;
		for (auto& i : prime) {
			ll aup = 0, cup = 0;
			for (int j = i; j <= a; j *= i) {
				aup += a / j;
			}
			for (int j = i; j <= b; j *= i) {
				aup -= b / j;
			}
			for (int j = i; j <= a - b; j *= i) {
				aup -= (a - b) / j;
			}
			for (int j = i; j <= c; j *= i) {
				cup += c / j;
			}
			for (int j = i; j <= d; j *= i) {
				cup -= d / j;
			}
			for (int j = i; j <= c - d; j *= i) {
				cup -= (c - d) / j;
			}
			if (aup > 0 && cup > 0) {
				result = 0;
				break;
			}
		}
		cout << result << '\n';
	}
	return 0;
}
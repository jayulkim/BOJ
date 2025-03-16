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

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll sum = 0;
	ll Min = LLONG_MAX;
	for (int i = 0; i < 7; i++) {
		ll num = 0;
		cin >> num;
		if (num % 2) {
			Min = min(Min, num);
			sum += num;
		}
	}
	if (Min == LLONG_MAX) {
		cout << -1;
		return 0;
	}
	cout << sum << '\n';
	cout << Min;
	return 0;
}
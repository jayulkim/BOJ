#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll> lll;
typedef tuple<pll, string, ll> pllsl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll a = 0, b = 0;
	cin >> a >> b;
	ll c = 0, d = 0;
	cin >> c >> d;
	ll e = 0, f = 0;
	cin >> e >> f;
	if (a == c) {
		if (e == a && ((b <= f && f <= d) || (d <= f && f <= b))) {
			cout << 2;
			return 0;
		}
		else {
			cout << 0;
			return 0;
		}
	}
	if (b == d) {
		if (f == b && ((a <= e && e <= c) || (c <= e && e <= a))) {
			cout << 2;
			return 0;
		}
		else {
			cout << 0;
			return 0;
		}
	}
	cout << 1;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	if (n > m) {
		swap(n, m);
	}
	ll Min = LLONG_MAX;
	for (ll i = 1; i * i <= n + n + m + k - 3; i++) {
		for (ll j = 1; j * i <= k + n + m + k - 3; j++) {
			Min = min({ Min, llabs(n - i) + llabs(m - j) + llabs(k - i * j), llabs(n - j) + llabs(m - i) + llabs(k - i * j) });
		}
	}
	cout << Min;
	return 0;
}
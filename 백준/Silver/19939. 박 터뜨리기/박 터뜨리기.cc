#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	if ((m * (m + 1) / 2) > n) {
		cout << -1;
		return 0;
	}
	if ((n - (m * (m + 1) / 2)) % m == 0) {
		cout << m - 1;
	}
	else {
		cout << m;
	}
	return 0;
}
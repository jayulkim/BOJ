#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	if (m >= n) {
		cout << 0;
		return 0;
	}
	if ((n * m) % 2) {
		cout << n - 1;
	}
	else {
		cout << n;
	}
	return 0;
}
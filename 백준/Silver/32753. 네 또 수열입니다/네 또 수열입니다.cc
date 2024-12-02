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
	cin >> n >> m;
	if (n == 1) {
		for (int i = 0; i < n * m - 1; i++) {
			cout << 1 << ' ';
		}
		cout << n;
		return 0;
	}
	if (n * m - 1 != m) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < n * m - 1; i++) {
		cout << 1 << ' ';
	}
	cout << n;
	return 0;
}
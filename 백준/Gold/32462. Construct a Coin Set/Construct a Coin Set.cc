#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<ll, ll> pll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	while (num--) {
		ll n = 0;
		cin >> n;
		if (n <= 5) {
			cout << -1 << '\n';
		}
		else {
			if (n % 2) {
				cout << 4 << '\n';
				cout << 1 << ' ' << n / 2 << ' ' << n / 2 + 1 << ' ' << n - 2 << '\n';
			}
			else {
				cout << 3 << '\n';
				cout << 1 << ' ' << n / 2 << ' ' << n - 2 << '\n';
			}
		}
	}
	return 0;
}
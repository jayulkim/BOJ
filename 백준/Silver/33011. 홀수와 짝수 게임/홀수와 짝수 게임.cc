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
	ll num = 0;
	cin >> num;
	while (num--) {
		cin >> n;
		ll a = 0, b = 0;
		for (int i = 0; i < n; i++) {
			ll num = 0;
			cin >> num;
			if (num % 2) {
				a++;
			}
			else {
				b++;
			}
		}
		if (a == b) {
			cout << "heeda0528" << '\n';
		}
		else {
			if (max(a, b) % 2) {
				cout << "amsminn" << '\n';
			}
			else {
				cout << "heeda0528" << '\n';
			}
		}
	}
	return 0;
}
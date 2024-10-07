#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	ll a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		a += (num / m);
		ll temp = num % m;
		for (int j = 0; j < num / m; j++) {
			temp -= (k - m);
			if (temp <= 0) {
				break;
			}
		}
		if (temp > 0) {
			b += temp;
		}
	}
	cout << a << '\n' << b;
	return 0;
}
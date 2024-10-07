#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	while (cin >> n) {
		cout.width(5);
		ll temp = 1;
		if (n == 0) {
			cout << right << n << " -> " << 1 << '\n';
		}
		else {
			for (int i = 1; i <= n; i++) {
				temp *= i;
				temp %= 10000000000;
				while (temp % 10 == 0) {
					temp /= 10;
				}
			}
			cout << right << n << " -> " << temp % 10 << '\n';
		}
	}
	return 0;
}
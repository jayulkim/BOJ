#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	cin >> n;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	if (n % 2 == 0) {
		cout << 2 * (n / 2) * (n / 2) - (n / 2);
	}
	else {
		cout << 2 * (n / 2) * (n / 2) + (n / 2);
	}
	return 0;
}
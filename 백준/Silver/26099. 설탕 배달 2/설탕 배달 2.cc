#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	cin >> n;
	if (n % 5 == 0) {
		cout << n / 5;
	}
	else if (n % 5 == 1) {
		if (n == 1) {
			cout << -1;
		}
		else {
			cout << (n / 5) + 1;
		}
	}
	else if (n % 5 == 2) {
		if (n == 2 || n == 7) {
			cout << -1;
		}
		else {
			cout << (n / 5) + 2;
		}
	}
	else if (n % 5 == 3) {
		cout << (n / 5) + 1;
	}
	else if (n % 5 == 4) {
		if (n == 4) {
			cout << -1;
		}
		else {
			cout << (n / 5) + 2;
		}
	}
	return 0;
}
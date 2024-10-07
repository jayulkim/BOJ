#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	if (n == 16) {
		cout << 3 << ' ' << 3 << '\n';
		cout << 1 << ' ' << 2 << '\n';
		cout << 1 << ' ' << 1 << '\n';
	}
	else if (n == (ll)pow(2, 16)) {
		cout << 4 << ' ' << 5 << '\n';
		cout << 1 << ' ' << 2 << ' ' << 3 << '\n';
		for (int i = 0; i < 4; i++) {
			cout << 1 << ' ';
		}
	}
	else if (n == (ll)pow(2, 8)) {
		cout << 4 << ' ' << 4 << '\n';
		cout << 1 << ' ' << 1 << ' ' << 2 << '\n';
		cout << 1 << ' ' << 1 << ' ' << 1 << '\n';
	}
	else if (n == (ll)pow(2, 32)) {
		cout << 6 << ' ' << 6 << '\n';
		cout << 1 << ' ' << 1 << ' ' << 1 << ' ' << 1 << ' ' << 1 << '\n';
		cout << 1 << ' ' << 1 << ' ' << 1 << ' ' << 1 << ' ' << 2 << '\n';
	}
	else {
		cout << -1;
	}
	return 0;
}
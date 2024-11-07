#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	if (n == m) {
		cout << 0;
		return 0;
	}
	if (n % llabs(n - m) == 0 || llabs(n - m) % n == 0) {
		cout << 1 << '\n';
		if (n > m) {
			cout << n - m;
		}
		else {
			cout << m - n;
		}
		return 0;
	}
	else {
		cout << 2 << '\n';
		cout << n * (m - 1) << '\n';
		cout << "-" << (n - 1) * m << '\n';
	}
	return 0;
}
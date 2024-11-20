#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n / 2; i++) {
		if (i != n - i) {
			cout << i << ' ' << n - i << ' ';
		}
		else {
			cout << i << ' ';
		}
	}
	cout << n;
	return 0;
}
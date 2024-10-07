#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<ll, ll> pll;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	vector<ll>v(n + 1);
	ll temp = n;
	for (int i = n; i >= 1; i--) {
		if (i % 2) {
			v[i] = temp;
			temp--;
		}
	}
	temp = 1;
	for (int i = n; i >= 1; i--) {
		if (i % 2 == 0) {
			v[i] = temp;
			temp++;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << v[i] << ' ';
	}
	return 0;
}
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
		cin >> n >> m;
		if (n < m && m % n == 0) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
	return 0;
}
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
	cin >> n >> m;
	ll count = 0;
	for (int i = 1; i <= n; i++) {
		ll temp = i;
		while (temp > 0) {
			if (temp % 10 == m) {
				count++;
			}
			temp /= 10;
		}
	}
	cout << count;
	return 0;
}
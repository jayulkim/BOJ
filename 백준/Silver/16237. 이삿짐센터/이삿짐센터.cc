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
	ll a = 0, b = 0;
	cin >> n >> m >> k >> a >> b;
	ll result = b;
	while (a > 0) {
		a--;
		if (n > 0) {
			n--;
		}
		result++;
	}
	while (k > 0) {
		k--;
		if (m > 0) {
			m--;
		}
		else if (n > 0) {
			n--;
			if (n > 0) {
				n--;
			}
		}
		result++;
	}
	while (m > 0) {
		m--;
		if (m > 0) {
			m--;
			if (n > 0) {
				n--;
			}
		}
		else if (n > 0) {
			n--;
			if (n > 0) {
				n--;
				if (n > 0) {
					n--;
				}
			}
		}
		result++;
	}
	result += (n + 4) / 5;
	cout << result;
	return 0;
}
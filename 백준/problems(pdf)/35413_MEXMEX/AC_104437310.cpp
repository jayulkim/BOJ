#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	if (!m) {
		for (int i = 0; i < n; i++) {
			cout << 0 << ' ';
		}
	}
	else if (m == 1) {
		for (int i = 1; i <= n; i++) {
			cout << i << ' ';
		}
	}
	else if (m == 2) {
		if (n < 2) {
			cout << -1;
		}
		else {
			for (int i = 0; i < n - 2; i++) {
				cout << 0 << ' ';
			}
			cout << 0 << ' ' << 2;
		}
	}
	else {
		if (n < m - 1) {
			cout << -1;
		}
		else {
			for (int i = m - 1; i < n; i++) {
				cout << 0 << ' ';
			}
			for (int i = 0; i < m - 1; i++) {
				cout << i << ' ';
			}			
		}
	}
	return 0;
}
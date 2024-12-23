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
	cin >> n;
	vector<ll>v = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	do {
		if (v[0] != 0 && v[4] != 0) {
			ll a = 0, b = 0;
			a += v[3];
			a += (10 * v[2]);
			a += (100 * v[2]);
			a += (1000 * v[1]);
			a += (10000 * v[0]);
			b += v[6];
			b += (10 * v[2]);
			b += (100 * v[5]);
			b += (1000 * v[3]);
			b += (10000 * v[4]);
			if (a + b == n) {
				cout << "  " << a << '\n';
				cout << "+ " << b << '\n';
				cout << "-------" << '\n';
				if (n >= 100000) {
					cout << " ";
				}
				else {
					cout << "  ";
				}
				cout << n;
				return 0;
			}
		}
	} while (next_permutation(v.begin(), v.end()));
	cout << "No Answer";
	return 0;
}
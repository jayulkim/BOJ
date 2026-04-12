#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	while (num--) {
		cin >> n >> m;
		ll a = min(n, m);
		ll b = 2 * n * m * a + ((2 * a + 1) * (a + 1) * a) / 3 - a * (a + 1) * (1 + n + m) + a + m * a + n * a;
		ll c = 2 * m * n * a + ((2 * a + 1) * (a + 1) * a) / 3 + a * (a + 1) * (1 - n - m) - n * a - m * a + n * (m - 1) + (n - 1) * m;
		if (n != m) {
			c += llabs(n - m);
		}
		cout << b << ' ' << c << '\n';
	}
	return 0;
}
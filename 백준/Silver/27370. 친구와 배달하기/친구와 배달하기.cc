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
		cin >> n >> m >> k;
		vector<ll>v;
		for (int i = 0; i < n; i++) {
			ll num = 0;
			cin >> num;
			v.push_back(num);
		}
		if (m > k) {
			swap(m, k);
		}
		ll a = 0, b = 0;
		vector<ll>vv;
		for (int i = 0; i < n; i++) {
			if (llabs(m - v[i]) < llabs(k - v[i])) {
				a += (2 * llabs(m - v[i]));
			}
			else if (llabs(m - v[i]) > llabs(k - v[i])) {
				b += (2 * llabs(k - v[i]));
			}
			else {
				vv.push_back(2 * llabs(m - v[i]));
			}
		}
		for (auto& i : vv) {
			if (a < b) {
				a += i;
			}
			else {
				b += i;
			}
		}
		cout << a + b << ' ' << llabs(a - b) << '\n';
	}
	return 0;
}
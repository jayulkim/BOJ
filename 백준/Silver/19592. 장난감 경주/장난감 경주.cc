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
			ll a = 0;
			cin >> a;
			v.push_back(a);
		}
		ll Max = 0;
		for (int i = 0; i < n - 1; i++) {
			Max = max(v[i], Max);
		}
		if (Max < v[n - 1]) {
			cout << 0 << '\n';
		}
		else {
			bool find = false;
			for (int i = v[n - 1] + 1; i <= k; i++) {
				if (m * v[n - 1] >(v[n - 1] + m - i) * Max) {
					cout << i << '\n';
					find = true;
					break;
				}
			}
			if (!find) {
				cout << -1 << '\n';
			}
		}
	}
	return 0;
}
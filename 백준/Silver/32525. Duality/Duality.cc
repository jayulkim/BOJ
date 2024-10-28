#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	while (num--) {
		ll n = 0;
		cin >> n;
		vector<pair<ll, ll>>v;
		for (int i = 0; i < n; i++) {
			ll x = 0, y = 0;
			cin >> x >> y;
			v.push_back({ x + (1LL << 29), y + 1 });
		}
		for (int i = 0; i < n; i++) {
			cout << i + 1 << ' ' << v[i].first << ' ' << v[i].second << '\n';
		}
	}
	return 0;
}
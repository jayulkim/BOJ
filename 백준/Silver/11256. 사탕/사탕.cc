#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	while (num--) {
		cin >> n >> m;
		vector<ll>v;
		for (int i = 0; i < m; i++) {
			ll a = 0, b = 0;
			cin >> a >> b;
			v.push_back(a * b);
		}
		sort(v.begin(), v.end(), greater<ll>());
		ll idx = 0;
		while (n > 0) {
			n -= v[idx];
			idx++;
		}
		cout << idx << '\n';
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
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
		ll n = 0, m = 0;
		cin >> n >> m;
		vector<ll>v;
		for (int i = 0; i < m; i++) {
			ll a = 0;
			cin >> a;
			v.push_back(a);
		}
		ll Min = 0;
		ll Max = 0;
		for (int i = 0; i < m; i++) {
			Min = max({ Min, min(v[i], n - v[i]) });
			Max = max({ Max, v[i], n - v[i] });
		}
		cout << Min << ' ' << Max << '\n';
	}
	return 0;
}
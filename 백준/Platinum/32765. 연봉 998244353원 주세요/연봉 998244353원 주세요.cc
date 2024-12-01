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
	vector<ll>v(100001);
	v[1] = n + 1;
	for (ll i = 2; i <= 100000; i++) {
		v[i] = v[i - 1] + (i - v[i - 1] % i);
	}
	ll temp = v[100000] - v[99999];
	for (int i = 0; i < m; i++) {
		ll num = 0;
		cin >> num;
		if (num <= 100000) {
			cout << v[num] << '\n';
		}
		else {
			cout << v[100000] + (num - 100000) * temp << '\n';
		}
	}
	return 0;
}
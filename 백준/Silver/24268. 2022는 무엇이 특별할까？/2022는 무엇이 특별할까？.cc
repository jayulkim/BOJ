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
	vector<ll>v;
	for (int i = 0; i < m; i++) {
		v.push_back(i);
	}
	ll Min = LLONG_MAX;
	do {
		if (v[0] != 0) {
			ll temp = 0;
			ll num = 1;
			for (int i = v.size() - 1; i >= 0; i--) {
				temp += (num * v[i]);
				num *= m;
			}
			if (temp > n) {
				Min = min(Min, temp);
			}
		}
	} while (next_permutation(v.begin(), v.end()));
	if (Min == LLONG_MAX) {
		cout << -1;
		return 0;
	}
	cout << Min;
	return 0;
}
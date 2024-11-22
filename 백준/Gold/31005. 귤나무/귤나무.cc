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
	ll Min = LLONG_MAX;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		Min = min(Min, num);
		v.push_back(num);
	}
	while (1) {
		if (m < Min) {
			break;
		}
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			if (m >= v[i]) {
				m -= v[i];
				sum += v[i];
			}
		}
		m %= sum;
	}
	cout << m;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<ll>v;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	ll count = 0;
	bool find = false;
	for (int i = 0; i < n; i++) {
		if (v[i] == m) {
			find = true;
		}
		if (find && v[i] == m) {
			count++;
			m += k;
		}
	}
	cout << count;
	return 0;
}
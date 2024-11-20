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
	cin >> n;
	vector<ll>v;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	ll count = 0;
	for (int i = 0; i < n - 1; i++) {
		if (v[i] > v[i + 1]) {
			count++;
		}
	}
	if (!count) {
		cout << n;
		return 0;
	}
	if (count >= 2) {
		cout << 0;
		return 0;
	}
	ll result = 0;
	for (int i = 0; i < n - 1; i++) {
		if (v[i] > v[i + 1]) {
			bool find = false;
			vector<ll>vv;
			for (int j = 0; j < n; j++) {
				if (j != i) {
					vv.push_back(v[j]);
				}
			}
			for (int j = 0; j < n - 2; j++) {
				if (vv[j] > vv[j + 1]) {
					find = true;
					break;
				}
			}
			if (!find) {
				result++;
			}
			vector<ll>().swap(vv);
			find = false;
			for (int j = 0; j < n; j++) {
				if (j != i + 1) {
					vv.push_back(v[j]);
				}
			}
			for (int j = 0; j < n - 2; j++) {
				if (vv[j] > vv[j + 1]) {
					find = true;
					break;
				}
			}
			if (!find) {
				result++;
			}
			break;
		}
	}
	cout << result;
	return 0;
}
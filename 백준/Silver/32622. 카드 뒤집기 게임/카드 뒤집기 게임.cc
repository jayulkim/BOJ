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
	ll result = 0;
	ll count = 1;
	vector<ll>vv;
	for (int i = 0; i < n - 1; i++) {
		if (v[i] != v[i + 1]) {
			result = max(result, count);
			vv.push_back(count);
			count = 1;
		}
		else {
			count++;
		}
	}
	if (count) {
		result = max(result, count);
		vv.push_back(count);
	}
	for (int i = 0; i < vv.size() - 1; i++) {
		result = max(result, vv[i] + vv[i + 1]);
	}
	cout << result;
	return 0;
}
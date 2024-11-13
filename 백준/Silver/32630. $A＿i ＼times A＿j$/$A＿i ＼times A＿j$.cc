#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	cin >> n;
	vector<ll>v;
	vector<ll>vv;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		if (num > 0) {
			v.push_back(num);
		}
		else {
			vv.push_back(num);
		}
		sum += num;
	}
	sort(v.begin(), v.end());
	sort(vv.begin(), vv.end());
	if (v.size() > 1) {
		ll temp = 0;
		for (int i = 0; i < v.size() - 2; i++) {
			temp += v[i];
		}
		temp += (2 * (v[v.size() - 2] * v.back()));
		for (auto& i : vv) {
			temp += i;
		}
		sum = max(sum, temp);
	}
	if (vv.size() > 1) {
		ll temp = 0;
		for (int i = 2; i < vv.size(); i++) {
			temp += vv[i];
		}
		temp += (2 * (vv[0] * vv[1]));
		for (auto& i : v) {
			temp += i;
		}
		sum = max(sum, temp);
	}
	cout << sum;
	return 0;
}
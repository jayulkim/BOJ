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
	vector<pll>v;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v.push_back({ num, 0 });
	}
	for (int i = 0; i < n; i++) {
		cin >> v[i].second;
	}
	vector<ll>vv;
	for (int i = 0; i < n; i++) {
		vv.push_back((v[i].first + v[i].second - 1) / v[i].second);
	}
	ll start = 1, end = 1000000000, mid = 0;
	ll Min = LLONG_MAX;
	while (start <= end) {
		mid = (start + end) / 2;
		ll sum = 0;
		for (auto& i : vv) {
			sum += max((ll)0, i - mid);
		}
		if (sum <= mid) {
			end = mid - 1;
			Min = min(Min, mid);
		}
		else {
			start = mid + 1;
		}
	}
	cout << Min;
	return 0;
}
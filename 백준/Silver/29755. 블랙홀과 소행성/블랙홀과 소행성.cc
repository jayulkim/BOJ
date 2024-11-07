#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<ll>v;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	vector<pll>vv;
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		vv.push_back({ a, b });
	}
	sort(v.begin(), v.end());
	sort(vv.begin(), vv.end());
	ll start = 0, end = 1e9, mid = 0;
	vector<ll>result;
	while (start <= end) {
		mid = (start + end) / 2;
		bool find = false;
		ll idx = 0;
		for (int i = 0; i < n; i++) {
			while (idx < m && llabs(v[i] - vv[idx].first) * vv[idx].second <= mid) {
				idx++;
			}
			if (idx == m) {
				find = true;
				break;
			}
		}
		if (!find) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
			result.push_back(mid);
		}
	}
	sort(result.begin(), result.end());
	cout << result[0];
	return 0;
}
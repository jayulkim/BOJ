#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	vector<ll>v;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num % m);
	}
	sort(v.begin(), v.end());
	ll temp = 0;
	vector<ll>result;
	for (int i = 0; i < k; i++) {
		ll num = 0;
		cin >> num;
		temp += num;
		temp %= m;
		ll start = 0, end = n - 1, mid = 0;
		vector<ll>vv;
		while (start <= end) {
			mid = (start + end) / 2;
			if (v[mid] > m - temp - 1) {
				end = mid - 1;
			}
			else {
				vv.push_back(v[mid]);
				start = mid + 1;
			}
		}
		if (vv.empty()) {
			result.push_back((v.back() + temp) % m);
		}
		else {
			sort(vv.begin(), vv.end());
			result.push_back((vv.back() + temp) % m);
		}
	}
	for (auto& i : result) {
		cout << i << ' ';
	}
	return 0;
}
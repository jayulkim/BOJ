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
		auto it = upper_bound(v.begin(), v.end(), m - temp - 1);
		if (it == v.begin()) {
			result.push_back((v[n - 1] + temp) % m);
		}
		else {
			it--;
			result.push_back((v[it - v.begin()] + temp) % m);
		}
	}
	for (auto& i : result) {
		cout << i << ' ';
	}
	return 0;
}
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
		v.push_back(llabs(num));
	}
	sort(v.begin(), v.end());
	ll result = 0, idx = 0;
	for (int i = 0; i < n; i++) {
		if (idx < m - 1) {
			idx++;
		}
		else {
			idx = 0;
			result += (2 * v[i]);
		}
	}
	if (idx) {
		result += (2 * v[n - 1]);
	}
	cout << result;
	return 0;
}
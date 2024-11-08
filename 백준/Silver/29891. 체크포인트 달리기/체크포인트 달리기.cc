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
	vector<ll>vv;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		if (num > 0) {
			v.push_back(num);
		}
		else {
			vv.push_back(-num);
		}
	}
	sort(v.begin(), v.end());
	sort(vv.begin(), vv.end());
	ll result = 0;
	for (int i = v.size() - 1; i >= 0; i -= m) {
		result += (2 * v[i]);
	}
	for (int i = vv.size() - 1; i >= 0; i -= m) {
		result += (2 * vv[i]);
	}
	cout << result;
	return 0;
}
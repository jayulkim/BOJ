#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<ll>v;
	vector<ll>vv;
	for (int i = 1; i <= n; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	for (int i = 1; i <= m; i++) {
		ll num = 0;
		cin >> num;
		vv.push_back(num);
	}
	sort(v.begin(), v.end(), greater<ll>());
	sort(vv.begin(), vv.end());
	ll result = 0;
	for (int i = 0; i < m && i < n; i++) {
		if (v[i] - vv[i] >= 0) {
			result += (v[i] - vv[i]);
		}
	}
	cout << result;
	return 0;
}
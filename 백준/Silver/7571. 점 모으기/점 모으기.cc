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
	cin >> n >> m;
	vector<ll>v;
	vector<ll>vv;
	vector<pll>ary;
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		v.push_back(a);
		vv.push_back(b);
		ary.push_back({ a, b });
	}
	sort(v.begin(), v.end());
	sort(vv.begin(), vv.end());
	ll result = 0;
	ll y = 0, x = 0;
	y = v[m / 2];
	x = vv[m / 2];
	for (int i = 0; i < m; i++) {
		result += llabs(ary[i].first - y);
		result += llabs(ary[i].second - x);
	}
	cout << result;
	return 0;
}
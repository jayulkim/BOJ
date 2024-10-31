#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<pll>v;
	vector<ll>mod;
	ll a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
	cin >> a >> b >> c >> d >> e >> f;
	v.push_back({ a, d });
	v.push_back({ b, e });
	v.push_back({ c, f });
	sort(v.begin(), v.end());
	for (int i = v.back().second; i < 1000000000; i += v.back().first) {
		if (i % a == d && i % b == e && i % c == f) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
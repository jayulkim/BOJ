#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	ll a = 0, b = 0, c = 0;
	vector<pair<ll, ll>>v;
	cin >> n >> a >> b >> c;
	v.push_back({ a / n + b / n + c / n, c });
	ll aa = a, bb = b, cc = c;
	cc -= (n - aa % n);
	aa += (n - aa % n);
	if (cc >= 0) {
		v.push_back({ aa / n + bb / n + cc / n, cc });
	}
	cc -= (n - bb % n);
	bb += (n - bb % n);
	if (cc >= 0) {
		v.push_back({ aa / n + bb / n + cc / n, cc });
	}
	c -= (n - b % n);
	b += (n - b % n);
	if (c >= 0) {
		v.push_back({ a / n + b / n + c / n, c });
	}
	sort(v.begin(), v.end());
	cout << v.back().second;
	return 0;
}
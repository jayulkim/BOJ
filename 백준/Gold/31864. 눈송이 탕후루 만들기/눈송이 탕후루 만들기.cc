#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
map<pll, vector<ll>>oneMap;
map<pll, vector<ll>>twoMap;
map<pll, vector<ll>>threeMap;
map<pll, vector<ll>>fourMap;
vector<ll>a;
vector<ll>b;
vector<ll>c;
vector<ll>d;
ll n = 0, m = 0;
ll gcd(ll a, ll b) {
	ll temp = a % b;
	while (temp > 0) {
		a = b;
		b = temp;
		temp = a % b;
	}
	return b;
}
bool compare(const pll& a, const pll& b) {
	return a.first * a.first + a.second * a.second < b.first * b.first + b.second * b.second;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<pll>v;
	for (int i = 0; i < n; i++) {
		ll x = 0, y = 0;
		cin >> x >> y;
		v.push_back({ x, y });
	}
	sort(v.begin(), v.end(), compare);
	for (auto& [x, y] : v) {
		if (x < 0 && y < 0) {
			ll num = gcd(llabs(x), llabs(y));
			threeMap[{llabs(x / num), llabs(y / num)}].push_back(x * x + y * y);
		}
		else if (x < 0 && y > 0) {
			ll num = gcd(llabs(x), llabs(y));
			twoMap[{llabs(x / num), llabs(y / num)}].push_back(x * x + y * y);
		}
		else if (x > 0 && y < 0) {
			ll num = gcd(llabs(x), llabs(y));
			fourMap[{llabs(x / num), llabs(y / num)}].push_back(x * x + y * y);
		}
		else if (x > 0 && y > 0) {
			ll num = gcd(llabs(x), llabs(y));
			oneMap[{llabs(x / num), llabs(y / num)}].push_back(x * x + y * y);
		}
		else if (x == 0 && y < 0) {
			a.push_back(y * y);
		}
		else if (x == 0 && y > 0) {
			b.push_back(y * y);
		}
		else if (x < 0 && y == 0) {
			c.push_back(x * x);
		}
		else if (x > 0 && y == 0) {
			d.push_back(x * x);
		}
	}
	ll Max = 0;
	for (int i = 0; i < m; i++) {
		ll x = 0, y = 0;
		cin >> x >> y;
		if (x < 0 && y < 0) {
			ll num = gcd(llabs(x), llabs(y));
			Max = max(Max, (ll)(upper_bound(threeMap[{llabs(x / num), llabs(y / num)}].begin(), threeMap[{llabs(x / num), llabs(y / num)}].end(), x * x + y * y) - threeMap[{llabs(x / num), llabs(y / num)}].begin()));
		}
		else if (x < 0 && y > 0) {
			ll num = gcd(llabs(x), llabs(y));
			Max = max(Max, (ll)(upper_bound(twoMap[{llabs(x / num), llabs(y / num)}].begin(), twoMap[{llabs(x / num), llabs(y / num)}].end(), x * x + y * y) - twoMap[{llabs(x / num), llabs(y / num)}].begin()));
		}
		else if (x > 0 && y < 0) {
			ll num = gcd(llabs(x), llabs(y));
			Max = max(Max, (ll)(upper_bound(fourMap[{llabs(x / num), llabs(y / num)}].begin(), fourMap[{llabs(x / num), llabs(y / num)}].end(), x * x + y * y) - fourMap[{llabs(x / num), llabs(y / num)}].begin()));
		}
		else if (x > 0 && y > 0) {
			ll num = gcd(llabs(x), llabs(y));
			Max = max(Max, (ll)(upper_bound(oneMap[{llabs(x / num), llabs(y / num)}].begin(), oneMap[{llabs(x / num), llabs(y / num)}].end(), x * x + y * y) - oneMap[{llabs(x / num), llabs(y / num)}].begin()));
		}
		else if (x == 0 && y < 0) {
			Max = max(Max, (ll)(upper_bound(a.begin(), a.end(), y * y) - a.begin()));
		}
		else if (x == 0 && y > 0) {
			Max = max(Max, (ll)(upper_bound(b.begin(), b.end(), y * y) - b.begin()));
		}
		else if (x < 0 && y == 0) {
			Max = max(Max, (ll)(upper_bound(c.begin(), c.end(), x * x) - c.begin()));
		}
		else if (x > 0 && y == 0) {
			Max = max(Max, (ll)(upper_bound(d.begin(), d.end(), x * x) - d.begin()));
		}
	}
	cout << Max;
	return 0;
}
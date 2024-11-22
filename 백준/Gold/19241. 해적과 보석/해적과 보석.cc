#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
bool compare(const pll& a, const pll& b) {
	return a.first - b.second > b.first - a.second;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	while (num--) {
		cin >> n;
		vector<pll>v;
		ll a = 0, b = 0;
		for (int i = 0; i < n; i++) {
			cin >> m >> k;
			v.push_back({ m, k });
		}
		sort(v.begin(), v.end(), compare);
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				a += v[i].first;
			}
			else {
				b += v[i].second;
			}
		}
		cout << a - b << '\n';
	}
	return 0;
}
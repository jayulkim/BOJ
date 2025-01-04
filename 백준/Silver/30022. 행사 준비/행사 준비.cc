#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
bool compare(const pll& a, const pll& b) {
	return a.second - a.first < b.second - b.first;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	vector<pll>v;
	for (int i = 0; i < n; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		v.push_back({ a, b });
	}
	sort(v.begin(), v.end(), compare);
	ll result = 0;
	for (int i = 0; i < k; i++) {
		result += v[i].second;
	}
	for (int i = k; i < n; i++) {
		result += v[i].first;
	}
	cout << result;
	return 0;
}
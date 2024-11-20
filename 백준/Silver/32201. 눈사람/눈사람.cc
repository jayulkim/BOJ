#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
map<ll, ll>Map;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<tp>v;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		Map[num] = i;
	}
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v.push_back({ Map[num] - i, n - i, num });
	}
	sort(v.begin(), v.end(), greater<tp>());
	auto [a, b, c] = v[0];
	ll Max = a;
	for (auto [a, b, c] : v) {
		if (Max == a) {
			cout << c << ' ';
		}
		else {
			break;
		}
	}
	return 0;
}
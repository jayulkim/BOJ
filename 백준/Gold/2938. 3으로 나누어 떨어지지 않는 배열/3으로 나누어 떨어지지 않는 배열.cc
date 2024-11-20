#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>v[3];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<pll>vv;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v[num % 3].push_back(num);
	}
	if (v[0].empty() && !v[1].empty() && !v[2].empty()) {
		cout << -1;
		return 0;
	}
	if (v[0].size() > (n + 1) / 2) {
		cout << -1;
		return 0;
	}
	while (!v[1].empty()) {
		if (v[0].size() > 1) {
			cout << v[0].back() << ' ';
			v[0].pop_back();
		}
		cout << v[1].back() << ' ';
		v[1].pop_back();
	}
	if (!v[0].empty()) {
		cout << v[0].back() << ' ';
		v[0].pop_back();
	}
	while (!v[2].empty()) {
		cout << v[2].back() << ' ';
		v[2].pop_back();
		if (!v[0].empty()) {
			cout << v[0].back() << ' ';
			v[0].pop_back();
		}
	}
	return 0;
}
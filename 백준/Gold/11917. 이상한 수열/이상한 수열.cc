#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<ll>v;
	for (int i = 0; i < n; i++) {
		cin >> m;
		v.push_back(m);
	}
	cin >> m;
	if (m <= n) {
		cout << v[m - 1];
		return 0;
	}
	sort(all(v));
	v.erase(unique(all(v)), v.end());
	ll temp = v.size();
	ll idx = lower_bound(all(v), temp) - v.begin();
	if (idx < v.size() && m >= n + v[idx] - temp + 1) {
		cout << v[idx];
	}
	else {
		cout << temp + (m - n - 1);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<ll, ll> pll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	cin >> n;
	vector<pll>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
	}
	for (int i = 0; i < n; i++) {
		cin >> v[i].second;
	}
	v[n - 1].first += v[n - 2].second;
	v[n - 1].second += v[n - 2].first;
	ll a = max(v[n - 1].first, v[n - 1].second);
	ll b = min(v[n - 1].first, v[n - 1].second);
	for (int i = 0; i < n - 2; i++) {
		a += max(v[i].first, v[i].second);
		b += min(v[i].first, v[i].second);
	}
	cout << llabs(a - b);
	return 0;
}
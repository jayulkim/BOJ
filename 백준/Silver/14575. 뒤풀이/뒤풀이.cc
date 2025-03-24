#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, char> plc;
typedef pair<string, ll> psl;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll, ll, ll, ll, ll, ll>llllllll;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<pll>v;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		v.push_back({ a, b });
	}
	ll start = 0, end = 1e9, mid = 0;
	ll Min = LLONG_MAX;
	while (start <= end) {
		mid = (start + end) / 2;
		ll a = 0, b = 0;
		bool find = false;
		for (auto& i : v) {
			if (i.first > mid) {
				find = true;
				break;
			}
			a += i.first;
			b += min(mid, i.second);
		}
		if (find) {
			start = mid + 1;
		}
		else {
			if (a <= m && m <= b) {
				Min = min(Min, mid);
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	if (Min == LLONG_MAX) {
		cout << -1;
		return 0;
	}
	cout << Min;
	return 0;
}
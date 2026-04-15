#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<ll>a(n);
	vector<ll>b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	sort(all(a));
	sort(all(b));
	ll start = 1, end = 1e18, mid = 0;
	ll result = LLONG_MAX;
	while (start <= end) {
		mid = (start + end) / 2;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			ll s = 0, e = n - 1, mi = 0;
			ll Max = -1;
			while (s <= e) {
				mi = (s + e) / 2;
				if (a[i] * b[mi] <= mid) {
					Max = max(Max, mi);
					s = mi + 1;
				}
				else {
					e = mi - 1;
				}
			}
			sum += Max + 1;
		}
		if (sum < m) {
			start = mid + 1;
		}
		else {
			result = min(result, mid);
			end = mid - 1;
		}
	}
	cout << result;
	return 0;
}
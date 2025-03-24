#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<ll>v;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	ll count = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			ll a = lower_bound(v.begin() + j + 1, v.end(), -(v[i] + v[j])) - v.begin(), b = upper_bound(v.begin() + j + 1, v.end(), -(v[i] + v[j])) - v.begin();
			count += b - a;
		}
	}
	cout << count;
	return 0;
}
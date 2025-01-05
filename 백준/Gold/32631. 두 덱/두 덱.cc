#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll a[5001];
ll b[5001];
ll aaa[5001];
ll bbb[5001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<ll>aa(5001);
	vector<ll>bb(5001);
	for (int i = 1; i <= n; i++) {
		cin >> aa[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> bb[i];
	}
	for (int i = 1; i <= n; i++) {
		a[i] = a[i - 1] + aa[i];
	}
	for (int i = 1; i <= n; i++) {
		b[i] = b[i - 1] + bb[i];
	}
	for (int i = n - m; i <= n; i++) {
		ll Min = LLONG_MAX;
		for (int j = i; j <= n; j++) {
			Min = min(Min, a[j] - a[j - i]);
		}
		aaa[i] = Min;
	}
	for (int i = n - m; i <= n; i++) {
		ll Min = LLONG_MAX;
		for (int j = i; j <= n; j++) {
			Min = min(Min, b[j] - b[j - i]);
		}
		bbb[i] = Min;
	}
	ll Min = LLONG_MAX;
	for (int i = n - m; i <= n; i++) {
		Min = min(Min, max(aaa[i], bbb[2 * n - m - i]));
	}
	cout << Min;
	return 0;
}
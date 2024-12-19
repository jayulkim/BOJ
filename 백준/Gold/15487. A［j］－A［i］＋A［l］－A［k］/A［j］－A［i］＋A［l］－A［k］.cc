#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll a[1000001];
ll b[1000001];
ll aa[1000001];
ll bb[1000001];
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
	ll Min = LLONG_MAX;
	for (int i = 1; i < n - 2; i++) {
		Min = min(Min, v[i - 1]);
		a[i] = v[i] - Min;
	}
	ll Max = -LLONG_MAX;
	for (int i = n - 2; i >= 2; i--) {
		Max = max(Max, v[i + 1]);
		b[i] = Max - v[i];
	}
	Max = -LLONG_MAX;
	for (int i = 1; i < n - 2; i++) {
		Max = max(Max, a[i]);
		aa[i] = Max;
	}
	Max = -LLONG_MAX;
	for (int i = n - 2; i >= 2; i--) {
		Max = max(Max, b[i]);
		bb[i] = Max;
	}
	ll result = -LLONG_MAX;
	for (int i = 1; i < n - 2; i++) {
		result = max(result, aa[i] + bb[i + 1]);
	}
	cout << result;
	return 0;
}
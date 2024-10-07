#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<ll, ll> pll;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<ll>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	ll idx = 0;
	bool find = false;
	for (int i = 0; i < n; i++) {
		if (v[i] >= m) {
			idx = i;
			find = true;
			break;
		}
	}
	if (!find) {
		idx = n;
	}
	ll result = n - idx;
	ll start = 0, end = idx - 1;
	while (start < end) {
		if (v[start] + v[end] >= m) {
			start++;
			end--;
			find = true;
			result++;
		}
		else {
			start++;
		}
	}
	if (!find) {
		cout << -1;
	}
	else {
		cout << result;
	}
	return 0;
}
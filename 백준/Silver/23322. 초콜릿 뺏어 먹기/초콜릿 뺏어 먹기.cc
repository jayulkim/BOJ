#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<ll>v;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	ll idx = m;
	ll result = 0;
	ll count = 0;
	while (idx < n) {
		if (v[idx] > v[idx - m]) {
			result += (v[idx] - v[idx - m]);
			v[idx] = v[idx - m];
			sort(v.begin(), v.end());
			count++;
		}
		else {
			idx++;
		}
	}
	cout << result << ' ' << count;
	return 0;
}
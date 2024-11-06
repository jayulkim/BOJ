#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
	vector<ll>yaksoo;
	for (int i = 1; i <= m; i++) {
		if (m % i == 0) {
			yaksoo.push_back(i);
		}
	}
	ll result = 0;
	for (int i = 0; i < n; i++) {
		ll Min = LLONG_MAX;
		for (auto& j : yaksoo) {
			Min = min(Min, llabs(v[i] - j));
		}
		result += Min;
	}
	cout << result;
	return 0;
}
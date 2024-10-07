#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	cin >> n;
	vector<ll>v(n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	ll temp = sum / n;
	if (sum % n == 0) {
		ll s = 0, t = 0;
		for (int i = 0; i < n; i++) {
			s += (v[i] - temp);
		}
		for (int i = 0; i < n; i++) {
			if (v[i] - temp > 0) {
				t += (v[i] - temp);
			}
		}
		if (s < 0) {
			cout << t - s;
		}
		else {
			cout << t;
		}
	}
	else {
		ll s = 0, t = 0;
		vector<ll>result;
		for (int i = 0; i < n; i++) {
			if (llabs(v[i] - temp) < llabs(v[i] - (temp + 1))) {
				result.push_back(v[i] - temp);
			}
			else {
				result.push_back(v[i] - (temp + 1));
			}
		}
		for (int i = 0; i < n; i++) {
			s += result[i];
			if (result[i] > 0) {
				t += result[i];
			}
		}
		if (s < 0) {
			cout << t - s;
		}
		else {
			cout << t;
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<ll>v;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
		sum += num;
	}
	if ((m / sum) % 2) {
		m -= ((m / sum) * sum);
		for (int i = n - 1; i >= 0; i--) {
			m -= v[i];
			if (m < 0) {
				cout << i + 1;
				break;
			}
			else if (m == 0) {
				cout << i;
				break;
			}
		}
	}
	else {
		m -= ((m / sum) * sum);
		for (int i = 0; i < n; i++) {
			m -= v[i];
			if (m < 0) {
				cout << i + 1;
				break;
			}
			else if (m == 0) {
				cout << i + 2;
				break;
			}
		}
	}
	return 0;
}
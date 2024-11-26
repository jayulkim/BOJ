#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<ll>v;
	vector<ll>vv;
	vector<ll>x;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		vv.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		x.push_back(num);
	}
	vector<ll>vvv;
	for (int i = 0; i < n; i++) {
		if (llabs(v[i] - vv[i]) % x[i]) {
			cout << -1;
			return 0;
		}
		else {
			if (v[i] == vv[i]) {
				vvv.push_back(0);
			}
			else {
				vvv.push_back(llabs(vv[i] - v[i]) / x[i]);
			}
		}
	}
	ll result = 0;
    ll temp = vvv[0] % 2;
	for (int i = 1; i < n; i++) {
        if (vvv[i] % 2 != temp) {
            cout << -1;
            return 0;
        }
        result = max(result, vvv[i]);
	}
	cout << max(result, vvv[0]);
	return 0;
}
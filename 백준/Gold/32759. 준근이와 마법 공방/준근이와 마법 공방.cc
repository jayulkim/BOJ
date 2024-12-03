#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
#define mod 1000000007
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<ll>vv;
	for (int i = 0; i < m; i++) {
		int num = 0;
		cin >> num;
		vv.push_back(num);
	}
	sort(vv.begin(), vv.end());
	vector<ll>v(1000005);
	if (vv.back() >= 0 && vv[vv.size() - 2] >= 0) {
		v[1] = vv.back();
		v[0] = vv[vv.size() - 2];
		for (int i = 2; i < n + 2; i++) {
			v[i] = ((v[i - 1] + mod) % mod + (v[i - 2] + mod) % mod + mod) % mod;
		}
		cout << (v[n + 1] + mod) % mod;
	}
	else if (vv.back() < 0 && vv[vv.size() - 2] < 0) {
		cout << (vv.back() + vv[vv.size() - 2] + mod) % mod;
	}
	else {
		ll result = -LLONG_MAX;
		while (result < 0 && n) {
			result = vv[vv.size() - 2] + vv.back();
			vv[vv.size() - 2] = result;
			n--;
		}
		if (!n) {
			cout << (result + mod) % mod;
			return 0;
		}
		v[1] = vv.back();
		v[0] = vv[vv.size() - 2];
		for (int i = 2; i < n + 2; i++) {
			v[i] = ((v[i - 1] + mod) % mod + (v[i - 2] + mod) % mod + mod) % mod;
		}
		cout << (v[n + 1] + mod) % mod;
	}
	return 0;
}
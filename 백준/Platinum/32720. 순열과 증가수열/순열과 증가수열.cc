#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
ll n = 0, m = 0, k = 0;
#define mod 1000000007
ll addmod(ll x, ll y, ll num) {
	if (x >= (num - y)) {
		return x - (num - y);
	}
	return x + y;
}
ll mulmod(ll x, ll y, ll num) {
	ll result = 0;
	while (y > 0) {
		if (y % 2) {
			result = addmod(result, x, num);
		}
		x = addmod(x, x, num);
		y /= 2;
	}
	return result;
}
ll powmod(ll x, ll y, ll num) {
	ll result = 1;
	while (y > 0) {
		if (y % 2) {
			result = mulmod(result, x, num);
		}
		x = mulmod(x, x, num);
		y /= 2;
	}
	return result;
}
ll comb(ll n, ll k) {
	ll up = 1;
	for (ll i = n; i >= n - k + 1; i--) {
		up = mulmod(up, i, mod);
	}
	ll down = 1;
	for (ll i = 2; i <= k; i++) {
		down = mulmod(down, i, mod);
	}
	return mulmod(up, powmod(down, mod - 2, mod), mod);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	vector<ll>v;
	vector<bool>visited(n + 1, false);
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			ll temp = 0;
			for (int j = i; j <= n; j += k) {
				temp++;
				visited[j] = true;
			}
			v.push_back(temp);
		}
	}
	ll result = 1;
	ll temp = n;
	for (auto& i : v) {
		result = mulmod(result, comb(temp, i), mod);
		temp -= i;
	}
	cout << result;
    return 0;
}
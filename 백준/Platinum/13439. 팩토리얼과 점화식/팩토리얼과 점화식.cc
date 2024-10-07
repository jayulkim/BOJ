#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll dp[1001][101][171];
bool ary[1001];
vector<ll>v;
ll addmod(ll x, ll y, ll num) {
	if (x >= (num - y)) {
		return x - (num - y);
	}
	return x + y;
}
ll mulmod(ll x, ll y, ll num) {
	ll result = 0;
	x %= num;
	y %= num;
	while (y > 0) {
		if (y % 2 == 1) {
			result = addmod(result, x, num);
		}
		x = addmod(x, x, num);
		y /= 2;
	}
	return result;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 2; i * i <= 1000; i++) {
		if (!ary[i]) {
			for (int j = i * i; j <= 1000; j += i) {
				ary[j] = true;
			}
		}
	}
	for (ll i = 2; i <= 1000; i++) {
		if (!ary[i]) {
			v.push_back(i);
		}
	}
	for (ll i = 2; i <= 1000; i++) {
		for (ll j = 0; j < v.size(); j++) {
			if (i < v[j]) {
				break;
			}
			ll start = v[j], sum = 0, temp = i;
			while (temp > 0) {
				sum += (i / start);
				start *= v[j];
				temp /= v[j];
			}
			dp[i][1][j] = sum;
		}
	}
	for (ll i = 2; i <= 1000; i++) {
		for (ll j = 2; j <= 100; j++) {
			for (ll k = 0; k < v.size(); k++) {
				dp[i][j][k] = addmod(dp[i - 1][j][k], dp[i][j - 1][k], 1000000009);
			}
		}
	}
	ll n = 0, k = 0;
	cin >> n >> k;
	ll result = 1;
	for (ll i = 0; i < v.size(); i++) {
		result = mulmod(result, dp[n][k][i] + 1, 1000000009);
	}
	cout << result;
	return 0;
}
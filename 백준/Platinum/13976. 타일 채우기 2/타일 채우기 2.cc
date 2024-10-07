#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll addmod(ll x, ll y, ll num) {
	if (x >= num - y) {
		return x - (num - y);
	}
	else {
		return x + y;
	}
}
ll mulmod(ll x, ll y, ll num) {
	ll result = 0;
	x %= num;
	while (y > 0) {
		if (y % 2 == 1) {
			result = addmod(result, x, num);
			result %= num;
		}
		x = addmod(x, x, num);
		x %= num;
		y /= 2;
	}
	return result;
}
ll** mulary(ll** x, ll** y, ll num) {
	ll** result = (ll**)malloc(sizeof(ll) * 2);
	for (int i = 0; i < 2; i++) {
		result[i] = (ll*)malloc(sizeof(ll) * 2);
		for (int j = 0; j < 2; j++) {
			result[i][j] = 0;
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			ll sum = 0;
			for (int k = 0; k < 2; k++) {
				sum = addmod(sum, ((x[i][k] % 1000000007) * (y[k][j] % 1000000007) + 1000000007) % 1000000007, 1000000007);
				sum %= num;
			}
			result[i][j] = sum;
		}
	}
	return result;
}
ll** powary(ll** x, ll y, ll num) {
	ll** result = (ll**)malloc(sizeof(ll) * 2);
	for (int i = 0; i < 2; i++) {
		result[i] = (ll*)malloc(sizeof(ll) * 2);
	}
	result[0][0] = 1;
	result[0][1] = 0;
	result[1][0] = 0;
	result[1][1] = 1;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			x[i][j] %= num;
		}
	}
	while (y > 0) {
		if (y % 2 == 1) {
			result = mulary(result, x, num);
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					result[i][j] %= num;
				}
			}
		}
		x = mulary(x, x, num);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				x[i][j] %= num;
			}
		}
		y /= 2;
	}
	return result;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	cin >> n;
	if (n % 2 == 1) {
		cout << 0;
		return 0;
	}
	ll** ary = (ll**)malloc(sizeof(ll) * 2);
	for (int i = 0; i < 2; i++) {
		ary[i] = (ll*)malloc(sizeof(ll) * 2);
	}
	ary[0][0] = 4;
	ary[0][1] = -1;
	ary[1][0] = 1;
	ary[1][1] = 0;
	ll** pow = (ll**)malloc(sizeof(ll) * 2);
	for (int i = 0; i < 2; i++) {
		pow[i] = (ll*)malloc(sizeof(ll) * 2);
	}
	pow = powary(ary, n / 2 - 1, 1000000007);
	cout << addmod(mulmod(pow[0][0], 3, 1000000007), pow[0][1], 1000000007);
	return 0;
}
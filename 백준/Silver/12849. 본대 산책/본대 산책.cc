#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<ll>>v = { {0, 1, 1, 0, 0, 0, 0, 0}, {1, 0, 1, 1, 0, 0, 0, 0}, {1, 1, 0, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 1, 1, 0, 0}, {0, 0, 1, 1, 0, 1, 1, 0}, {0, 0, 0, 1, 1, 0, 0, 1}, {0, 0, 0, 0, 1, 0, 0, 1}, {0, 0, 0, 0, 0, 1, 1, 0} };
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
		}
		x = addmod(x, x, num);
		y /= 2;
	}
	return result;
}
vector<vector<ll>> arymul(vector<vector<ll>> x, vector<vector<ll>> y, ll num) {
	vector<vector<ll>>result = { {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0} };
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			ll sum = 0;
			for (int k = 0; k < 8; k++) {
				sum = addmod(sum, mulmod(x[i][k], y[k][j], num), num);
			}
			result[i][j] = sum;
		}
	}
	return result;
}
vector<vector<ll>> arypow(vector<vector<ll>> x, ll y, ll num) {
	vector<vector<ll>>result = { {1, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 1} };;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			x[i][j] %= num;
		}
	}
	while (y > 0) {
		if (y % 2 == 1) {
			result = arymul(result, x, num);
		}
		x = arymul(x, x, num);
		y /= 2;
	}
	return result;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	cin >> n;
	vector<vector<ll>>result = arypow(v, n, 1000000007);
	cout << result[0][0];
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
vector<vector<ll>>v;
int n = 0, m = 0;
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
	vector<vector<ll>>result;
	result.resize(n);
	for (int i = 0; i < n; i++) {
		result[i].resize(n);
		for (int j = 0; j < n; j++) {
			result[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ll sum = 0;
			for (int k = 0; k < n; k++) {
				sum = addmod(sum, mulmod(x[i][k], y[k][j], num), num);
			}
			result[i][j] = sum;
		}
	}
	return result;
}
vector<vector<ll>> arypow(vector<vector<ll>> x, ll y, ll num) {
	vector<vector<ll>>result;
	result.resize(n);
	for (int i = 0; i < n; i++) {
		result[i].resize(n);
		for (int j = 0; j < n; j++) {
			result[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		result[i][i] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
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
	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		v[i].resize(n);
		for (int j = 0; j < n; j++) {
			v[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		int start = 0, end = 0;
		cin >> start >> end;
		v[start - 1][end - 1] = 1;
		v[end - 1][start - 1] = 1;
	}
	ll d = 0;
	cin >> d;
	v = arypow(v, d, 1000000007);
	cout << v[0][0];
	return 0;
}
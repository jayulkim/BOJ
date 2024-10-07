#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0;
vector<vector<ll>>matrix;
vector<vector<ll>>mulmat(vector<vector<ll>>a, vector<vector<ll>>b) {
	vector<vector<ll>>result(n, vector<ll>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ll sum = 0;
			for (int k = 0; k < n; k++) {
				sum += (((a[i][k] % 1000) * (b[k][j] % 1000)) % 1000);
				sum %= 1000;
			}
			result[i][j] = sum % 1000;
		}
	}
	return result;
}
vector<vector<ll>>powmat(vector<vector<ll>>a, ll b) {
	vector<vector<ll>>result(n, vector<ll>(n, 0));
	for (int i = 0; i < n; i++) {
		result[i][i] = 1;
	}
	while (b > 0) {
		if (b % 2 == 1) {
			result = mulmat(result, a);
		}
		a = mulmat(a, a);
		b /= 2;
	}
	return result;
}
vector<vector<ll>>solve(vector<vector<ll>>a, ll b) {
	if (b == 1) {
		return matrix;
	}
	vector<vector<ll>>temp = powmat(matrix, b / 2);
	for (int i = 0; i < n; i++) {
		temp[i][i]++;
		temp[i][i] %= 1000;
	}
	vector<vector<ll>>v = mulmat(solve(matrix, b / 2), temp);
	if (b % 2 == 1) {
		vector<vector<ll>>ary = powmat(matrix, b);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				v[i][j] %= 1000;
				v[i][j] += (ary[i][j] % 1000);
				v[i][j] %= 1000;
			}
		}
		return v;
	}
	return v;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		matrix.push_back({});
		for (int j = 0; j < n; j++) {
			ll num = 0;
			cin >> num;
			matrix[i].push_back(num % 1000);
		}
	}
	matrix = solve(matrix, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] % 1000 << ' ';
		}
		cout << '\n';
	}
	return 0;
}
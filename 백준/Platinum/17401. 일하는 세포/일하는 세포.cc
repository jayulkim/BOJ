#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
#define mod 1000000007
vector<vector<ll>>v;
vector<vector<vector<ll>>>Map;
vector<vector<ll>>mulmat(vector<vector<ll>>a, vector<vector<ll>>b) {
	vector<vector<ll>>result(m, vector<ll>(m, 0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			ll sum = 0;
			for (int k = 0; k < m; k++) {
				sum += ((a[i][k] % mod) * (b[k][j] % mod)) % mod;
				sum %= mod;
			}
			result[i][j] = sum % mod;
		}
	}
	return result;
}
vector<vector<ll>>powmat(vector<vector<ll>>a, ll b) {
	vector<vector<ll>>result(m, vector<ll>(m, 0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (i == j) {
				result[i][j] = 1;
			}
		}
	}
	while (b > 0) {
		if (b % 2) {
			result = mulmat(result, a);
		}
		a = mulmat(a, a);
		b /= 2;
	}
	return result;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		vector<ll>vv;
		for (int j = 0; j < m; j++) {
			if (i == j) {
				vv.push_back(1);
			}
			else {
				vv.push_back(0);
			}
		}
		v.push_back(vv);
	}
	for (int i = 0; i < n; i++) {
		vector<vector<ll>>temp(m, vector<ll>(m, 0));
		ll num = 0;
		cin >> num;
		for (int j = 0; j < num; j++) {
			ll a = 0, b = 0, c = 0;
			cin >> a >> b >> c;
			temp[a - 1][b - 1] = c;
		}
		v = mulmat(v, temp);
		Map.push_back(temp);
	}
	vector<vector<ll>>result = powmat(v, k / n);
	for (int i = 0; i < k % n; i++) {
		result = mulmat(result, Map[i]);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << result[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
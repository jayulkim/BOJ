#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pld;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	cin >> n;
	vector<vector<ld>>v(n, vector<ld>(n + 1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + 1; j++) {
			cin >> v[i][j];
		}
	}
	vector<ld>result;
	for (int i = 0; i < n - 1; i++) {
		ld idx = i, Max = 0;
		for (int j = i + 1; j < n; j++) {
			if (Max < v[j][i]) {
				Max = v[j][i];
				idx = j;
			}
		}
		for (int j = 0; j < n + 1; j++) {
			swap(v[i][j], v[idx][j]);
		}
		for (int j = i + 1; j < n; j++) {
			ld temp = v[j][i] / v[i][i];
			for (int k = i; k < n + 1; k++) {
				v[j][k] -= (temp * v[i][k]);
			}
		}
	}
	result.push_back(v[n - 1][n] / v[n - 1][n - 1]);
	for (int i = n - 2; i >= 0; i--) {
		ld sum = 0;
		ll idx = 0;
		for (int j = n - 1; j >= i + 1; j--) {
			sum += (v[i][j] * result[idx++]);
		}
		result.push_back(round((v[i][n] - sum) / v[i][i]));
	}
	reverse(result.begin(), result.end());
	for (auto& i : result) {
		cout << i << ' ';
	}
	return 0; 
}
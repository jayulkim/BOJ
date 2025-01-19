#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll dp[201][300001];
#define mod 1000000007
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<pll>v(201);
	for (int i = 1; i <= n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	ll start = 0, end = 0;
	cin >> start >> end;
	vector<ll>vv(201);
	for (int i = 1; i <= n; i++) {
		vv[i] = v[i].first * v[i].second * 96 / (1000 * 60);
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= end; j++) {
			if (j >= vv[i]) {
				dp[i][j] = ((dp[i - 1][j - vv[i]] % mod) + (dp[i - 1][j] % mod)) % mod;
			}
			else {
				dp[i][j] = dp[i - 1][j] % mod;
			}
		}
	}
	ll result = 0;
	for (int i = start; i <= end; i++) {
		result += (dp[n][i] % mod);
		result %= mod;
	}
	cout << result % mod;
	return 0;
}
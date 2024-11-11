#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0;
vector<vector<ll>>dp(1001, vector<ll>(1001, -1));
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	dp[0][0] = 1 % m;
	dp[1][0] = 1 % m;
	dp[1][1] = 1 % m;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = 1 % m;
		for (int j = 1; j <= i - 1; j++) {
			dp[i][j] = ((dp[i - 1][j] % m) + (dp[i - 1][j - 1] % m)) % m;
			dp[i][j] %= m;
		}
		dp[i][i] = 1 % m;
	}
	ll count = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (!dp[i][j]) {
				count++;
			}
		}
	}
	cout << count;
	
	return 0;
}
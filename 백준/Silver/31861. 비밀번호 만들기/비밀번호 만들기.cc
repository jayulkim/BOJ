#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
ll dp[1001][27];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	if (n == 0) {
		ll result = 1;
		for (int i = 0; i < m; i++) {
			result *= 26;
			result %= 1000000007;
		}
		cout << result % 1000000007;
		return 0;
	}
	for (int i = 0; i < 26; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= m; i++) {
		for (int j = 0; j < 26; j++) {
			if (j - n >= 0) {
				for (int k = j - n; k >= 0; k--) {
					dp[i][j] += (dp[i - 1][k] % 1000000007);
					dp[i][j] %= 1000000007;
				}
			}
			if (j + n < 26) {
				for (int k = j + n; k < 26; k++) {
					dp[i][j] += (dp[i - 1][k] % 1000000007);
					dp[i][j] %= 1000000007;
				}
			}
		}
	}
	ll sum = 0;
	for (int i = 0; i < 26; i++) {
		sum += (dp[m][i] % 1000000007);
		sum %= 1000000007;
	}
	cout << sum % 1000000007;
	return 0; 
}
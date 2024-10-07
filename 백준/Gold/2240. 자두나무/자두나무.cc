#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1001][31][3], n = 0, m = 0;
ll ary[1001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> ary[i];
	}
	for (int i = 1; i <= n; i++) {
		if (ary[i] == 1) {
			dp[i][0][1] = dp[i - 1][0][1] + 1;
		}
		for (int j = 1; j <= m; j++) {
			if (ary[i] == 1) {
				dp[i][j][1] = max(dp[i][j][1], max(dp[i - 1][j][1] + 1, dp[i - 1][j - 1][2] + 1));
				dp[i][j][2] = max(dp[i][j][2], max(dp[i - 1][j][2], dp[i - 1][j - 1][1]));
			}
			else if (ary[i] == 2) {
				dp[i][j][1] = max(dp[i][j][1], max(dp[i - 1][j][1], dp[i - 1][j - 1][2]));
				dp[i][j][2] = max(dp[i][j][2], max(dp[i - 1][j][2] + 1, dp[i - 1][j - 1][1] + 1));
			}
		}
	}
	cout << max(dp[n][m][1], dp[n][m][2]);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
ll dp[100001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 2;
	dp[4] = 3;
	dp[5] = 3;
	for (int i = 6; i <= 100000; i++) {
		dp[i] = (dp[i - 2] % 1000000009 + dp[i - 4] % 1000000009 + dp[i - 6] % 1000000009) % 1000000009;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		cout << dp[m] << '\n';
	}
	return 0;
}
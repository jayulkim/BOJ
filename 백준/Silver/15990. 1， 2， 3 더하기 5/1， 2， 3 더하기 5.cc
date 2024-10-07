#include <bits/stdc++.h>
using namespace std;
int dp[100001][4];
int addmod(int x, int y, int num) {
	if (x >= num - y) {
		return x - (num - y);
	}
	else {
		return x + y;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;
	for (int i = 4; i <= 100000; i++) {
		dp[i][1] = addmod(dp[i - 1][2], dp[i - 1][3], 1000000009);
		dp[i][2] = addmod(dp[i - 2][1], dp[i - 2][3], 1000000009);
		dp[i][3] = addmod(dp[i - 3][1], dp[i - 3][2], 1000000009);
	}
	int num = 0;
	cin >> num;
	while (num--) {
		int n = 0;
		cin >> n;
		cout << addmod(addmod(dp[n][1], dp[n][2], 1000000009), dp[n][3], 1000000009) << '\n';
	}
	
	return 0;
}
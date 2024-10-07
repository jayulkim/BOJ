#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[4001][4001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a = "", b = "";
	cin >> a >> b;
	for (int i = 0; i < a.length(); i++) {
		for (int j = 0; j < b.length(); j++) {
			if (a[i] == b[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				dp[i + 1][j + 1] = 0;
			}
		}
	}
	int result = 0;
	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			result = max(result, dp[i][j]);
		}
	}
	cout << result;
	return 0;
}
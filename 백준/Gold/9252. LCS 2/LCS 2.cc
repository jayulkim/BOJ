#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a = "";
	string b = "";
	cin >> a >> b;
	for (int i = 1; i <= b.length(); i++) {
		for (int j = 1; j <= a.length(); j++) {
			if (a[j - 1] == b[i - 1] && dp[i - 1][j - 1] + 1 >= dp[i - 1][j] && dp[i - 1][j - 1] >= dp[i][j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	string str = "";
	int result = dp[b.length()][a.length()];
	int bound = 1001;
	cout << result << '\n';
	for (int i = b.length(); i >= 1; i--) {
		for (int j = a.length(); j >= 1; j--) {
			if (a[j - 1] == b[i - 1] && dp[i][j] == result && j < bound) {
				str += a[j - 1];
				bound = j;
				result--;
				break;
			}
		}
	}
	for (int i = str.length() - 1; i >= 0; i--) {
		cout << str[i];
	}
	return 0;
}
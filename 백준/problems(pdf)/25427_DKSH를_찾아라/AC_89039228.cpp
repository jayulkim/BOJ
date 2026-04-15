#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;
ll dp[5][100001];
string temp = "DKSH";
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	string str = "";
	cin >> str;
	for (int i = 1; i <= n; i++) {
		if (temp[0] == str[i - 1]) {
			dp[1][i] = dp[1][i - 1] + 1;
		}
		else {
			dp[1][i] = dp[1][i - 1];
		}
	}
	for (int i = 2; i <= 4; i++) {
		for (int j = 1; j <= n; j++) {
			if (temp[i - 1] == str[j - 1]) {
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = dp[i][j - 1];
			}
		}
	}
	cout << dp[4][n];
	return 0;
}
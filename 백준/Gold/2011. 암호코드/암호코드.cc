#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll dp[5001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str = "";
	cin >> str;
	if (str[0] == '0') {
		cout << 0;
		return 0;
	}
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= str.length(); i++) {
		if (str[i - 1] == '0') {
			if (str[i - 2] == '0') {
				cout << 0;
				return 0;
			}
			string temp = "";
			temp += str[i - 2];
			temp += str[i - 1];
			if (stoll(temp) <= 26 && stoll(temp) >= 1) {
				dp[i] = dp[i - 2] % 1000000;
			}
			else {
				cout << 0;
				return 0;
			}
		}
		else {
			if (str[i - 2] == '0') {
				dp[i] = dp[i - 1] % 1000000;
			}
			else {
				string temp = "";
				temp += str[i - 2];
				temp += str[i - 1];
				if (stoll(temp) <= 26 && stoll(temp) >= 1) {
					dp[i] = ((dp[i - 1] % 1000000) + (dp[i - 2] % 1000000)) % 1000000;
				}
				else {
					dp[i] = dp[i - 1] % 1000000;
				}
			}
		}
	}
	cout << dp[str.length()];
	return 0;
}
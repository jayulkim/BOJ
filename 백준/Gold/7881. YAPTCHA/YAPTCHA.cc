#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool ary[3000008];
int dp[1000001];
int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(0);
	for (int i = 2; i * i <= 3000007; i++) {
		if (!ary[i]) {
			for (int j = i * i; j <= 3000007; j += i) {
				ary[j] = true;
			}
		}
	}
	dp[1] = 0;
	for (int i = 2; i <= 1000000; i++) {
		if (!ary[3 * i + 7]) {
			dp[i] = dp[i - 1] + 1;
		}
		else {
			dp[i] = dp[i - 1];
		}
	}
	int num = 0;
	cin >> num;
	while (num--) {
		int n = 0;
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}
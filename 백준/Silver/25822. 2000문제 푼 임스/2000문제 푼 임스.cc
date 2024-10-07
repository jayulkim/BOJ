#include <bits/stdc++.h>
using namespace std;
int dp[100001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie();
	double c = 0;
	int n = 0;
	cin >> c >> n;
	int count = c / 0.99;
	if (c > 2) {
		count = 2;
	}
	int Max = 0;
	for (int i = 1; i <= n; i++) {
		int num = 0;
		cin >> num;
		Max = max(Max, num);
		if (num == 0) {
			dp[i] = dp[i - 1] + 1;
		}
		else {
			dp[i] = dp[i - 1];
		}
	}
	int start = 0, end = 1;
	int result = 0;
	while (end <= n) {
		if (dp[end] - dp[start] <= count) {
			result = max(result, end - start);
			end++;
		}
		else {
			start++;
		}
	}
	cout << result << '\n' << Max;
	return 0;
}
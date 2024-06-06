#include <bits/stdc++.h>
using namespace std;
int dp[2001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		int Max = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (v[i] < v[j]) {
				Max = max(Max, dp[j]);
			}
		}
		dp[i] = Max + 1;
	}
	int result = 0;
	for (int i = 1; i <= n; i++) {
		result = max(result, dp[i]);
	}
	cout << n - result;
	return 0;
}
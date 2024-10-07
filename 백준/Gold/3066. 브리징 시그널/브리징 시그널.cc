#include <bits/stdc++.h>
using namespace std;
int dp[40001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	while (num--) {
		int n = 0;
		cin >> n;
		vector<int>v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		dp[0] = v[0];
		int idx = 0;
		for (int i = 1; i < n; i++) {
			if (dp[idx] < v[i]) {
				dp[++idx] = v[i];
			}
			else {
				int start = 0, end = idx, mid = 0;
				while (start < end) {
					mid = (start + end) / 2;
					if (dp[mid] >= v[i]) {
						end = mid;
					}
					else {
						start = mid + 1;
					}
				}
				dp[end] = v[i];
			}	
		}
		cout << idx + 1 << '\n';
		memset(dp, 0, sizeof(dp));
	}
 	return 0;
}
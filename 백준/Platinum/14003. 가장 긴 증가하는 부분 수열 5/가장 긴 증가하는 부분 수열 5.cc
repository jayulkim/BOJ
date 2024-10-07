#include <bits/stdc++.h>
using namespace std;
int dp[1000001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	vector<int>result;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int idx = 0;
	dp[0] = v[0];
	result.push_back(0);
	for (int i = 1; i < n; i++) {
		if (dp[idx] < v[i]) {
			dp[++idx] = v[i];
			result.push_back(idx);
		}
		else {
			int start = 0;
			int end = idx;
			int mid = 0;
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
			result.push_back(end);
		}
	}
	cout << idx + 1 << '\n';
	vector<int>solve;
	for (int i = n - 1; i >= 0; i--) {
		if (result[i] == idx) {
			solve.push_back(v[i]);
			idx--;
		}
	}
	reverse(solve.begin(), solve.end());
	for (auto& i : solve) {
		cout << i << ' ';
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int dp[10001];
int Find[10001];
int main(void) {
	int n = 0;
	cin >> n;
	vector<int>up(n);
	for (int i = 0; i < n; i++) {
		cin >> up[i];
	}
	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		Find[num - 1] = i;
	}
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		v[i] = Find[up[i] - 1];
	}
	dp[0] = v[0];
	int idx = 0;
	vector<int>result;
	for (int i = 0; i < n; i++) {
		if (dp[idx] < v[i]) {
			dp[++idx] = v[i];
			result.push_back(idx);
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
			result.push_back(end);
		}
	}
	cout << idx + 1 << '\n';
	vector<int>solve;
	for (int i = n - 1; i >= 0; i--) {
		if (result[i] == idx) {
			solve.push_back(i);
			idx--;
		}
	}
	vector<int>vv;
	for (int i = 0; i < solve.size(); i++) {
		vv.push_back(up[solve[i]]);
	}
	sort(vv.begin(), vv.end());
	for (auto& i : vv) {
		cout << i << ' ';
	}
 	return 0;
}
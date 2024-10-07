#include <bits/stdc++.h>
using namespace std;
int dp[100001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<pair<int, int>>A(n);
	vector<int>B(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i].first;
		A[i].second = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}
	sort(A.begin(), A.end());
	vector<int>ary;
	for (int i = 0; i < n; i++) {
		int start = 0;
		int end = n - 1;
		int mid = 0;
		while (start <= end) {
			mid = (start + end) / 2;
			if (A[mid].first == B[i]) {
				ary.push_back(A[mid].second);
				break;
			}
			if (A[mid].first > B[i]) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	dp[0] = ary[0];
	int idx = 0;
	for (int i = 1; i < n; i++) {
		if (dp[idx] < ary[i]) {
			dp[++idx] = ary[i];
		}
		else {
			int start = 0;
			int end = idx;
			int mid = 0;
			while (start < end) {
				mid = (start + end) / 2;
				if (dp[mid] >= ary[i]) {
					end = mid;
				}
				else {
					start = mid + 1;
				}
			}
			dp[end] = ary[i];
		}
	}
	cout << idx + 1;
	return 0;
}
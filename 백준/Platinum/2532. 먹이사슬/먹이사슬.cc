#include <bits/stdc++.h>
using namespace std;
int dp[500001];
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first < b.first;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<pair<int, int>>v(n);
	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), compare);
	v.erase(unique(v.begin(), v.end()), v.end());
	dp[0] = v[v.size() - 1].second;
	int idx = 0;
	for (int i = v.size() - 2; i >= 0; i--) {
		if (dp[idx] <= v[i].second) {
			dp[++idx] = v[i].second;
		}
		else {
			int start = 0, end = idx, mid = 0;
			while (start < end) {
				mid = (start + end) / 2;
				if (dp[mid] > v[i].second) {
					end = mid;
				}
				else {
					start = mid + 1;
				}
			}
			dp[end] = v[i].second;
		}
	}
	cout << idx + 1;
	return 0;
}
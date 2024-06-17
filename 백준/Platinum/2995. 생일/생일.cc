#include <bits/stdc++.h>
using namespace std;
int dp[100001];
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
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), compare);
	reverse(v.begin(), v.end());
	dp[0] = v[0].second;
	int idx = 0;
	vector<int>result(n);
	for (int i = 1; i < n; i++) {
		if (dp[idx] <= v[i].second) {
			dp[++idx] = v[i].second;
			result[i] = idx;
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
			result[i] = end;
		}
	}
	cout << idx + 1 << '\n';
	vector<pair<int, int>>solve;
	for (int i = n - 1; i >= 0; i--) {
		if (result[i] == idx) {
			solve.push_back(v[i]);
			idx--;
		}
	}
	sort(solve.begin(), solve.end(), compare);
	for (auto& i : solve) {
		cout << i.first << ' ' << i.second << '\n';
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int dp[100001];
bool Find[100001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<pair<int, int>>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	vector<int>log;
	int idx = 0;
	dp[0] = v[0].second;
	log.push_back(0);
	for (int i = 1; i < n; i++) {
		if (dp[idx] < v[i].second) {
			dp[++idx] = v[i].second;
			log.push_back(idx);
		}
		else {
			int start = 0, end = idx, mid = 0;
			while (start < end) {
				mid = (start + end) / 2;
				if (dp[mid] >= v[i].second) {
					end = mid;
				}
				else {
					start = mid + 1;
				}
			}
			dp[end] = v[i].second;
			log.push_back(end);
		}
	}
	cout << n - idx - 1 << '\n';
	vector<int>vv;
	for (int i = n - 1; i >= 0; i--) {
		if (idx == log[i]) {
			vv.push_back(i);
			idx--;
		}
	}
	for (int i = 0; i < vv.size(); i++) {
		Find[vv[i]] = true;
	}
	vector<int>solve;
	for (int i = 0; i < n; i++) {
		if (!Find[i]) {
			solve.push_back(v[i].first);
		}
	}
	sort(solve.begin(), solve.end());
	for (auto& i : solve) {
		cout << i << '\n';
	}
	return 0;
}